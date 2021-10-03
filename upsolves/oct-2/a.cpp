#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vector<ll>> dp;
vector<ll> nums;

ll go(ll idx, ll diff) {
    if (idx == sz(nums)) {
        if (diff != 1e5) return INT_MIN;
        return 0;
    }

    auto &ans = dp[idx][diff];
    if (ans != -1) return ans;
    ans = go(idx + 1, diff - nums[idx]) + nums[idx];
    ans = max(ans, go(idx + 1, diff + nums[idx]) + nums[idx]);
    ans = max(ans, go(idx + 1, diff));
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    nums.resize(n);
    for (auto &x : nums) cin >> x;
    sort(all(nums));

    int sum = 0;
    for (int i : nums) sum += i;

    dp = vector<vector<ll>>(n+10, vector<ll>(2 * 1e5 + 10, -1));
    ll ans = go(0, 1e5);

    cout << (ans / 2) + (sum - ans) << endl;

    return 0;
}
