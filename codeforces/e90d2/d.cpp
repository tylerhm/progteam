#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll gain(vi even, vi odd) {
    ll bestSum = LLONG_MIN, runningSum = 0;
    for (int i = 0; i < sz(even); i++) {
        runningSum += odd[i] - even[i];
        bestSum = max(bestSum, runningSum);
        runningSum = max(runningSum, 0LL);
    }
    return bestSum;
}

void solve(int t) {
    int n; cin >> n;
    vi nums(n); for (auto &x : nums) cin >> x;
    vi evens, odds;

    if (sz(nums) & 1) {

    } else {
        ll evenSum = 0;
        for (int i = 0; i < n; i++) {
            if (i & 1) odds.push_back(nums[i]);
            else evens.push_back(nums[i]), evenSum += nums[i];
        }

        cout << evenSum << ' ' << gain(evens, odds) << endl;
        ll ans = evenSum + max(0LL, gain(evens, odds));
        cout << ans << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
        solve(tt);

    return 0;
}

