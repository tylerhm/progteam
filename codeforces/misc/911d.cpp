#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vector<int> nums(n);
    for (auto & x : nums) cin >> x;

    bool even = true;
    for (int i = 0; i < sz(nums); i++)
        for (int j = i + 1; j < sz(nums); j++)
            if (nums[j] < nums[i]) even = !even;
    
    int q; cin >> q;
    rep(i, 0, q) {
        int l, r; cin >> l >> r;
        int swaps = (r - l + 1) / 2;
        if (swaps&1) even = !even;
        cout << (even ? "even" : "odd") << endl;
    }

    return 0;    
}
