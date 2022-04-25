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
	if (n & 1) {
		if (k > 1) {
			cout << "NO\n";
			return;
		}
		cout << "YES\n";
		for (int r = 1; r <= n; r++)
			cout << r << "\n";
		return;
	}
	cout << "YES\n";
	int even = 0, odd = -1;
	for (int r = 0; r < n; r++) {
		for (int i = 0; i < k; i++) {
			if (r & 1) cout << (even += 2) << ' ';
			else cout << (odd += 2) << ' ';
		}
		cout << "\n";
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();

    return 0;
}

