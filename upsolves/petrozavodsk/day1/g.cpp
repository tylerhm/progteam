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

	int N; cin >> N;
	vi P(N), A(N), B(N);
	for (auto &x : P) cin >> x, x--;
	for (auto &x : A) cin >> x;
	for (auto &x : B) cin >> x;

	vi cycle;
	vector<vector<ll>> dp;
	bool firstBlue;
	auto go = [&](int cycleIdx, bool lastBlue, auto &&go) -> ll {
		if (cycleIdx == sz(cycle)) return (lastBlue && !firstBlue) ? B[cycle[0]] : 0;

		auto &ans = dp[cycleIdx][lastBlue];
		if (ans != -1) return ans;

		ans = LLONG_MAX;
		// Color blue
		ans = min(ans, go(cycleIdx + 1, true, go) + B[cycle[cycleIdx]]);
		// Color red (if from blue add both)
		ans = min(
					ans,
					go(cycleIdx + 1, false, go) +
						A[cycle[cycleIdx]] +
						(lastBlue ? B[cycle[cycleIdx]] : 0)
				);

		return ans;
	};

	ll ans = 0;
	auto solveCycle = [&]() {
		// Start with red
		dp = vector<vector<ll>>(sz(cycle), vector<ll>(2, -1));
		firstBlue = false;
		ll blueStart = go(1, false, go) + A[cycle[0]];

		// Start with blue
		for (int i = 0; i < sz(cycle); i++)
			for (int j = 0; j < 2; j++)
				dp[i][j] = -1;
		firstBlue = true;
		ll redStart = go(1, true, go) + B[cycle[0]];

		ans += min(blueStart, redStart);
	};

	vector<bool> visited(N, false);
	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		cycle.clear(); cycle.push_back(i);
		for (int j = P[i]; j != i; j = P[j])
			cycle.push_back(j), visited[j] = true;

		if (sz(cycle) == 1) continue;
		solveCycle();
	}

	cout << ans << nl;

    return 0;
}

