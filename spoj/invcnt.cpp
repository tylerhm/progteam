#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(int pos, ll dif) { // a[pos] += dif
        for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
    }
    ll query(int pos) { // sum of values in [0, pos)
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos-1];
        return res;
    }
    int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
        // Returns n if no sum is >= sum, or -1 if empty sum is.
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1 << 25; pw; pw >>= 1) {
            if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
                pos += pw, sum -= s[pos-1];
        }
        return pos;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    rep(i,0,n) {
        int m; cin >> m;
        vector<int> nums(m);
        for (auto &x : nums) cin >> x;

        // coordinate compress
        vector<int> sorted = nums;
        sort(all(sorted));

        map<ll, int> compressed;
        for (int i = 0; i < m; i++)
            compressed[sorted[i]] = i;

        FT tree(m);

        ll invs = 0;
        for (int i = m-1; i >= 0; i--) {
            invs += tree.query(compressed[nums[i]]);
            tree.update(compressed[nums[i]], 1);
        }

        cout << invs << endl;
    }

    return 0;    
}
