#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n; cin >> n;
    while (n--)
    {
        ll np, p, g; cin >> np >> p >> g;
        ll numChains = ((np + g - 1) / g);
        ll numOccupied = np - numChains;
        cout << numOccupied * (p - 1) + numChains * p << "\n";
    }

    return 0;
}
