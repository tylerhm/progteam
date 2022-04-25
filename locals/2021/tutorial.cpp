#include <bits/stdc++.h>
using namespace std;

// #define MULTI
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1e9+7;

void solve(int tc) {
	int n, k, s; cin >> n >> k >> s;
	vi vals(n); for (auto &x : vals) cin >> x;
	sort(all(vals));
	vector<ll> dp(n, -1);
	auto go = [&](int idx, auto &&go) -> ll {
		if (idx >= n) return 1;
		auto &ans = dp[idx];
		if (ans != -1) return ans;
		ans = 0;
		for (int sz = 1; sz <= s; sz++) {
			int newStart = idx + sz;

			if (newStart >= n || vals[newStart-1] - vals[idx] <= k)
				ans += go(newStart, go);
			else break;
		}
		ans %= mod;
		return ans;
	};
	cout << go(0, go) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int tc = 1;
#ifdef MULTI
	int t; cin >> t;
	for (; tc <= t; tc++)
#endif
		solve(tc);

    return 0;
}

