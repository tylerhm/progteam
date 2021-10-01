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
        vector<pii> nums;
        for (int i = 1; i <= n; i++) {
            int val; cin >> val;
            if (val != 0)
                nums.emplace_back(val, i);
        }
        sort(all(nums));
     
        map<pii, int> ans;
        int lo = 0, cnt = 0;
        while (sz(nums) - lo > 1) {
            int bck = sz(nums)-1;
            ans[{nums[lo].second, nums[bck].second}]++;
            cnt++;
            nums[lo].first--;
            if (nums[lo].first == 0) lo++;
            nums[bck].first--;
            while (bck > lo && nums[bck].first < nums[bck-1].first)
                swap(nums[bck], nums[bck-1]), bck--;
        }
     
        cout << cnt << endl;
        for (auto &[p, c] : ans) {
            int a = p.first, b = p.second;
            for (int i = 0; i < c; i++) cout << a << ' ' << b << "\n";
        }
    }
     
    int main() {
        cin.tie(0)->sync_with_stdio(0);
        cin.exceptions(cin.failbit);
     
        int t; cin >> t;
        rep(tt, 0, t) solve();
     
        return 0;
    }