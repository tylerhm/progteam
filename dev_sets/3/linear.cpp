#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll extendedGCD(ll a, ll b, ll& x, ll& y)
{
    if (b == 0)
    {
        x = 1; y = 0;
        return a;
    }

    ll x1, y1;
    ll g = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

void calcInitialXY(ll a, ll b, ll c, ll&x, ll& y)
{
    ll g = extendedGCD(a, b, x, y);
    c /= g;
    x = x*x;
    y = y*c;
}

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        ll a, b; cin >> a >> b;
        ll l, h; cin >> l >> h;
        ll cnt = 0;

        ll x0, y0;
        calcInitialXY(a, b, 1, x0, y0);

        ll g = gcd(a, b);

        ll increment = b / g;
        ll k = 1;
        if (increment < 0)
            k = (ll)floor(1.0 * -x0 / increment);
        else
            k = (ll)ceil(1.0 * -x0 / increment);

        ll x1, x2;
        x1 = (x0 + b / g * 1);
        x2 = (x0 + b / g * 2);
        ll diff = x2 - x1;

        cnt = (h - l) / diff-1;
        
        cout << cnt << "\n";
    }

    return 0;
}
