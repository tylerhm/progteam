#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

void solve() {
    ll x, y; cin >> y >> x;
    ll z = max(x, y);
    ll z2 = (z-1)*(z-1), ans;
    if (z&1) {
        if (y == z)
            ans = z2+x;
        else
            ans = z2+2*z-y;
    } else {
        if (x == z)
            ans = z2+y;
        else
            ans = z2+2*z-x;
    }
    cout << ans << "\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
