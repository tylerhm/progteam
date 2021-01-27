#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

#define MOD 1000000007

int power(ll x, ll y) {
    ll res = 1;

    x = x % MOD;

    if (x == 0) return 0;

    while (y > 0) {
        if (y & 1)
            res = (res*x) % MOD;
        
        y = y>>1;
        x = (x*x) % MOD;
    }

    return res;
}

void solve(int t) {
    ll n, x; cin >> n >> x;
    ll twoPowN = power(2, n) - 1;
    cout << ((twoPowN * x) % MOD) << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 0; tt < t; tt++)
        solve(tt);

    return 0;
}
