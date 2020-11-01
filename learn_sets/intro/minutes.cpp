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
        int d, h, m; cin >> d >> h >> m;
        cout << (m + h * 60 + d * 60 * 24) << "\n";
    }

    return 0;
}
