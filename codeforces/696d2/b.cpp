#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

ll gcd(ll a, ll b) {
    if (!b)
        return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

void solve(int t) {
    ll d; cin >> d;
    ll m1 = 1, m2;
    m1 += d;
    m2 = m1 + d;
    cout << lcm(m1, m2) << nl;
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
