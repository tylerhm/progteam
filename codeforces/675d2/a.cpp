#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        int a, b, c; cin >> a >> b >> c;
        cout << (ll)a + (ll)b + (ll)c - 1 << "\n";
    }
    return 0;
}
