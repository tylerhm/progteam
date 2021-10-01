#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    for (auto &x : nums) cin >> x;

    vector<string> ans;
    for (int i = 0; i < n - 1; i++) {
        int mi = INT_MAX, midx = -1;
        for (int j = i; j < n; j++) {
            if (nums[j] < mi) {
                mi = nums[j];
                midx = j;
            }
        }
        if (mi != nums[i]) {
            int bck = nums[midx];
            for (int j = midx; j > i; j--) nums[j] = nums[j-1];
            nums[i] = bck;
            ans.push_back(to_string(i+1) + " " + to_string(midx+1) + " " + to_string(midx - i) + "\n");
        }
    }

    cout << sz(ans) << endl;
    for (string s : ans) cout << s;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    rep(tt, 0, t) solve();

    return 0;
}
