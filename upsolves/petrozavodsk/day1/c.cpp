#include <limits>
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
	vi B(N), C(N);
	for (auto &x : B) cin >> x;
	for (auto &x : C) cin >> x;

	vector<pair<ll, ll>> intervals;
	intervals.emplace_back(0, 0);
	int curStart = INT_MIN, curEnd = INT_MIN;
	for (int i = 0; i < N; i++) {
		if (C[i] < B[i]) continue;
		int intervalStart = C[i];
		int intervalEnd = B[i];
		bool overlap = !(intervalStart < curEnd || curStart < intervalEnd);
		if (overlap) {
			curStart = max(curStart, intervalStart);
			curEnd = min(curEnd, intervalEnd);
		} else {
			if (curStart != INT_MIN)
				intervals.emplace_back(curEnd, curStart);
			curStart = intervalStart;
			curEnd = intervalEnd;
		}
	}
	intervals.emplace_back(curEnd, curStart);

	vector<ll> dp(sz(intervals), -1);
	ll furthestLocation = max(C.back(), B.back());
	auto go = [&](int curInterval, auto &&go) -> ll {
		auto &ans = dp[curInterval];
		if (ans != -1) return ans;

		auto [l, r] = intervals[curInterval];

		ans = LLONG_MAX;

		// Go all the way to right and then come back
		ans = min(ans, (furthestLocation - r) + (furthestLocation - l));

		// Double back and take next
		if (curInterval < sz(intervals) - 1)
			ans = min(ans, go(curInterval + 1, go) + (r - l) * 2 + (intervals[curInterval + 1].second - r));
		else ans = min(ans, (r - l) * 2 + (furthestLocation - r));

		return ans;
	};

	// dist to first coin + solve
	cout << go(0, go) << endl;

    return 0;
}

