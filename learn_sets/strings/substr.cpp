#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct H {
    typedef uint64_t ull;
    ull x; H(ull x=0) : x(x) {}
#define OP(O,A,B) H operator O(H o) { ull r = x; asm \
    (A "addq %%rdx, %0\n adcq $0,%0" : "+a"(r) : B); return r; }
    OP(+,,"d"(o.x)) OP(*,"mul %1\n", "r"(o.x) : "rdx")
    H operator-(H o) { return *this + ~o.x; }
    ull get() const { return x + !~x; }
    bool operator==(H o) const { return get() == o.get(); }
    bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct HashInterval {
    vector<H> ha, pw;
    HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
        pw[0] = 1;
        rep(i,0,sz(str))
            ha[i+1] = ha[i] * C + str[i],
            pw[i+1] = pw[i] * C;
    }
    H hashInterval(int a, int b) { // hash [a, b)
        return ha[b] - ha[a] * pw[b - a];
    }
};

vector<H> getHashes(string& str, int length) {
    if (sz(str) < length) return {};
    H h = 0, pw = 1;
    rep(i,0,length)
        h = h * C + str[i], pw = pw * C;
    vector<H> ret = {h};
    rep(i,length,sz(str)) {
        ret.push_back(h = h * C + str[i] - pw * str[i-length]);
    }
    return ret;
}

H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string big; cin >> big;
    int sqr = sqrt(sz(big));
    HashInterval intervalHashes(big);

    set<H> hashedHashes;
    for (int i = 1; i <= sqr; i++) {
        vector<H> hashes = getHashes(big, i);
        for (auto h : hashes) hashedHashes.insert(h);
    }

    int q; cin >> q;
    int cnt = 0;
    rep(i, 0, q) {
        string sub; cin >> sub;
        H hash = hashString(sub);

        if (sz(sub) <= sqr) {
            cnt += hashedHashes.count(hash);
        } else {
            int len = sz(sub);
            for (int i = 0; i+len <= sz(big); i++) {
                if (intervalHashes.hashInterval(i, i+len) == hash) {
                    cnt++;
                    break;
                }
            }
        }
    }

    cout << cnt << endl;

    return 0;    
}
