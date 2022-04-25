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
    for (auto &x : nums)
        cin >> x;
    sort(all(nums));

    int last = INT_MIN;
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] != last + 1)
            total += nums[i];
        last = nums[i];
    }

    cout << total << endl;

    return 0;
}

