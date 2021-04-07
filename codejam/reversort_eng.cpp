#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int t) {
    ll len, cost; cin >> len >> cost;

    string ans = "";

    ll min_cost = len - 1;
    ll max_cost = ((len * (len + 1)) / 2) - 1;

    if (cost < min_cost || cost > max_cost) ans = "IMPOSSIBLE";
    else {
        vector<int> nums(len);
        for (int i = 0; i < len; i++) nums[i] = i+1;

        ll rem_cost = cost;
        for (int i = 0; i < len - 1; i++) {
            ll rem_iter = len - i - 1;

            if (rem_cost == rem_iter) break;

            ll rem_iter_after_rev = rem_iter - 1;
            ll rev_cost = len - i;

            if (rem_cost >= rem_iter_after_rev + rev_cost) {
                rem_cost -= rev_cost;
                ll rev_start = i / 2;
                ll rev_end = len - ((i+1) / 2);
                reverse(begin(nums) + rev_start, begin(nums) + rev_end);
            }
            else rem_cost--;
        }

        for (int num : nums) ans += to_string(num) + " ";
        ans = ans.substr(0, ans.length() - 1);
    }


    cout << "Case #" << t << ": " << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
        solve(tt);

    return 0;    
}
