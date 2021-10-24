#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define filename "cbt"

int getRHS(int lo, int hi) {
	int range = hi - lo;
	int rightHalfStart = (1 << (31 - __builtin_clz(range)));
	if (rightHalfStart == range) rightHalfStart >>= 1;
	rightHalfStart += lo;
	return rightHalfStart;
}

string dive(int lo, int hi, int d) {

	if (lo == hi - 1) return "";

	int rightHalfStart = getRHS(lo, hi);
	if (d < rightHalfStart)
		return "L" + dive(lo, rightHalfStart, d);
	return "R" + dive(rightHalfStart, hi, d);
}

ll dive(int lo, int hi, int idx, string& path) {
	if (idx == sz(path)) return lo;

	int rightHalfStart = getRHS(lo, hi);
	if (path[idx] == 'L') return dive(lo, rightHalfStart, idx+1, path);
	return dive(rightHalfStart, hi, idx+1, path);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
	freopen(filename ".in", "r", stdin), freopen(filename ".out", "w", stdout);

	int n, q; cin >> n >> q;

	for (int i = 0; i < q; i++) {
		char Q; cin >> Q;
		if (Q == 'A') {
			int d; cin >> d;
			cout << dive(0, n, d) << endl;
		} else {
			string path; cin >> path;
			cout << dive(0, n, 0, path) << endl;
		}
	}

    return 0;
}

