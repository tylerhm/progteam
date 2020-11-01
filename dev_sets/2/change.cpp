#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n; cin >> n;
    int q, d, ni, p;
    for (int i = 0; i < n; i++)
    {
        int c; cin >> c;
        q = c / 25;
        c -= q * 25;
        d = c / 10;
        c -= d * 10;
        ni = c / 5;
        c -= ni * 5;
        cout << i+1 << " " << q << " QUARTER(S), " << d << " DIME(S), " << ni << " NICKEL(S), " << c << " PENNY(S)" << "\n";
    }

    return 0;
}
