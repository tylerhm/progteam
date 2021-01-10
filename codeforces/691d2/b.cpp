#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n; cin >> n;

    ll locs = 0, mult = 0;
    ll ret;
    if (n&1) {
        locs = 1;
        for (ll i = 1; i <= n; i += 2) {
            locs++;
            mult++;
        }
        ret = 2*locs*mult;
    }
    else {
        locs = 1;
        mult = 1;
        for (ll i = 2; i <= n; i += 2) {
            locs++;
            mult++;
        }
        ret = locs*mult;
    }

    cout << ret << "\n";

    return 0;
}
