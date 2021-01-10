#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {

}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n; cin >> n;
    ll evens = n/3;

    ll ans = 0;
    for (int i = 3; i <= n; i+=3) ans += n-i;
    ans += 2*((evens)*(evens+1)/2);

    cout << ans << nl;

    return 0;
}
