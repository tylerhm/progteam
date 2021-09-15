#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef uint64_t ull;
static int C; // initialized below

template<int M, class B>
struct A {
	int x; B b; A(int x=0) : x(x), b(x) {}
	A(int x, B b) : x(x), b(b) {}
	A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
	A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
	A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
	explicit operator ull() { return x ^ (ull) b << 21; }
};
typedef A<1000000007, A<1000000009, unsigned>> H;

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

    timeval tp;
	gettimeofday(&tp, 0);
	C = (int)tp.tv_usec; // (less than modulo)
	assert((ull)(H(1)*2+1-3) == 0);

    string inp; cin >> inp;
    HashInterval intervals(inp);
    int len = sz(inp);

    vector<int> prefSufMatches;
    for (int i = 1; i <= len; i++)
        if ((ull)intervals.hashInterval(0, i) == (ull)intervals.hashInterval(len-i, len))
            prefSufMatches.push_back(i);

    int lo = 0, hi = sz(prefSufMatches) - 1, mid, ans = -1;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        int prefLen = prefSufMatches[mid];

        ull hash = (ull)intervals.hashInterval(0, prefLen);
        bool valid = false;
        for (int i = 1; i <= len-prefLen-1; i++) {
            if (hash == (ull)intervals.hashInterval(i, i+prefLen)) {
                valid = true;
                break;
            }
        }

        if (valid) {
            lo = mid + 1;
            ans = mid;
        } else hi = mid - 1;
    }

    if (ans == -1 || prefSufMatches[ans] == 0) {
        cout << "Just a legend" << endl;
    } else cout << inp.substr(0, prefSufMatches[ans]) << endl;

    return 0;    
}
