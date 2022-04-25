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
	ll n, x, y; cin >> n >> x >> y;
	vector<ll> nums(n);
	for (auto &x : nums) cin >> x;

	set<ll> found;
	found.insert(x);
	for (auto x : nums) {
		set<ll> newFound;
		for (auto v : found) {
			newFound.insert(v ^ x);
			newFound.insert(v + x);
		}
		found = newFound;
	}
	for (auto x : found) if (x == y) {
		cout << "Alice\n";
		return;
	}

	cout << "Bob\n";
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();

	return 0;
}

