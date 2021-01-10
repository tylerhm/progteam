#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n; cin >> n;
    string ans = "";
    if (n >= 1) ans += "9";
    if (n >= 2) ans += "8";
    if (n >= 3) ans += "9";
    for (int i = 3; i < n; i++)
        ans += ('0'+((i-3)%10));
    cout << ans << nl;
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
