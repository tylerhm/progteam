#include <climits>
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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int n; cin >> n;
	vector<pii> spies, houses;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char val; cin >> val;
			if (val == 'S') spies.emplace_back(i, j);
			if (val == 'H') houses.emplace_back(i, j);
		}
	}

	int maxDist = 0;
	for (auto [x, y] : spies) {
		int minDist = INT_MAX;
		for (auto [ox, oy] : houses) {
			int dist = abs(ox - x) + abs(oy - y);
			minDist = min(dist, minDist);
		}
		maxDist = max(maxDist, minDist);
	}

	cout << maxDist << endl;

    return 0;
}

