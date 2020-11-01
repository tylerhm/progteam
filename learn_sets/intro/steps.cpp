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
        int m; cin >> m;
        double d; cin >> d;
        double t, total = 0;
        for (int i = 0; i < m; i++) 
        {
            cin >> t;
            total += d / t;
        }
        printf("%.2f\n", total);
    }

    return 0;
}
