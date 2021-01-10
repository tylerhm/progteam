#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n; cin >> n;
    int setOne = 0, setTwo = 0;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(all(nums), greater<int>());
    for (int i = 0; i < n; i++) {
        if (setOne < setTwo) setOne += nums[i];
        else setTwo += nums[i];
    }
    cout << ((setOne==setTwo)?"YES":"NO") << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tt; cin >> tt;
    for (int t = 1; t <= tt; t++)
        solve(t);

    return 0;
}
