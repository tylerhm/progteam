#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m; cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    ll ans = 0;
    for (int i = 1; i < n; i++) ans = __gcd(ans, a[i] - a[0]);
    for (int i = 0; i < m; i++) {
        ll bv; cin >> bv;
        ll ret = __gcd(a[0] + bv, ans);
        cout << ret << " ";
    }

    return 0;
}
