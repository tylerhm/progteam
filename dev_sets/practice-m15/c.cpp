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
    vi nums(n);
    for (auto &x : nums) cin >> x;

    int passes = 0;

    while (nums.size()) {
        passes++;
        int i;
        for (i = 0; i < nums.size(); i++)
            if (nums[i-1] > nums[i]) break;
        nums.erase(nums.begin(), nums.begin() + i);
    }

    cout << passes << '\n';

    return 0;    
}
