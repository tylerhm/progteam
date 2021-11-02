#include <bits/stdc++.h>
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
	vi nums(n);
	for (auto &x : nums) cin >> x;
	vi prefSum(n+1);
	for (int i = 0; i < n; i++)
		prefSum[i + 1] = prefSum[i] + nums[i];

	vector<vi> dp(n+10, vi(n+10,-1));
	auto go = [&](int startIdx, int size, auto &&go) -> int {
		if (size == 1) return nums[startIdx];

		auto &ans = dp[startIdx][size];
		if (ans != -1) return ans;

		ans = INT_MAX;
		int leftSz = 1, rightSz = size - 1;
		for (;leftSz <= size - 1; leftSz++, rightSz--)
			ans = min(ans, go(startIdx, leftSz, go) + go(startIdx + leftSz, rightSz, go)) + prefSum[startIdx + leftSz] - prefSum[startIdx] + prefSum[startIdx + size] - prefSum[startIdx + leftSz];

		return ans;
	};

	cout << go(0, n, go) << endl;

    return 0;
}

