#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

void solve(ll n) {
    vector<ll> nums(n);
    for (auto &v : nums) cin >> v;

    if (n == 1) {
        cout << 1 << nl;
        return;
    }

    int firstDiff = nums[n-1] - nums[n-2];
    int i;
    for (i = n-1; i > 0 && nums[i] - nums[i-1] == firstDiff; i--);
    cout << i+1 << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    ll n;
    while (true) {
        try {
            cin >> n;
            solve(n);
        }
        catch (...) {
            return 0;
        }
    }
    return 0;
}
