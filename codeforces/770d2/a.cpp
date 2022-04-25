#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <list>
#include <numeric>
#include <random>
#include <tuple>
#include <map>
#include <set>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;

	if (k == 0) {
		cout << 1 << endl;
		return;
	}

	int lo = 0, hi = n - 1;
	bool pal = true;
	while (lo < hi) if (s[lo++] != s[hi--]) {
		pal = false;
		break;
	}

	if (pal) cout << 1 << endl;
	else cout << 2 << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();

    return 0;
}

