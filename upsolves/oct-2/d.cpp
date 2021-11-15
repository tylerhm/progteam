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

vector<H> pwOfC;
void precompPws(int len) {
    H c = C;
    pwOfC.resize(len + 1);
    for (int pw = 1; pw <= len; pw++) {
        pwOfC[pw] = c;
        c = c * C;    
    }
}

vector<H> rotationHashes(string& s) {
    vector<H> hashes;
    HashInterval h(s);
    hashes.push_back(h.hashInterval(0, sz(s)));
    for (int i = 1; i < sz(s); i++) {
        H left = h.hashInterval(0, i);
        H right = h.hashInterval(i, sz(s));
        right = right * pwOfC[i];
        hashes.push_back(left + right);
    }
    return hashes;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m, k; cin >> n >> m >> k;
    vector<string> puzzle(n);
    for (auto &x : puzzle) cin >> x;

    // get the cycle length that we need
    int cycleLength = min(k, lcm(n, m));
    precompPws(cycleLength);
    
    // get all possible hashes
    map<H, int> hashes;

    // horizontal
    for (int i = 0; i < n; i++) {
        string hori = "";
        for (int j = 0; j < cycleLength; j++)
            hori += puzzle[i][j % m];
        for (H h : rotationHashes(hori))
            hashes[h]++;
        reverse(all(hori));
        for (H h : rotationHashes(hori))
            hashes[h]++;
    }

    // vertical
    for (int i = 0; i < m; i++) {
        string vert = "";
        for (int j = 0; j < cycleLength; j++)
            vert += puzzle[j % n][i];
        for (H h : rotationHashes(vert))
            hashes[h]++;
        reverse(all(vert));
        for (H h : rotationHashes(vert))
            hashes[h]++;
    }

    // down-right
    for (int i = 0; i < m; i++) {
        string downRight = "";
        for (int j = 0; j < cycleLength; j++)
            downRight += puzzle[j % n][(i + j) % m];
        for (H h : rotationHashes(downRight))
            hashes[h]++;
        reverse(all(downRight));
        for (H h : rotationHashes(downRight))
            hashes[h]++;
    }

    // down-left
    for (int i = 0; i < m; i++) {
        string downLeft = "";
        for (int j = 0; j < cycleLength; j++)
            downLeft += puzzle[j % n][(((i - j) % m) + m) % m];
        for (H h : rotationHashes(downLeft))
            hashes[h]++;
        reverse(all(downLeft));
        for (H h : rotationHashes(downLeft))
            hashes[h]++;
    }

    ll denom = 0;
    ll num = 0;
    for (auto &[_, cnt] : hashes) {
        denom += cnt;
        num += cnt * cnt;
        cout << cnt << endl;
    }
    denom *= denom;

    ll actualDenom = __gcd(num, denom);
    cout << num << ' ' << denom << ' ' << actualDenom << endl;
    cout << (num / actualDenom) << '/' << (denom / actualDenom) << endl;

    return 0;
}
