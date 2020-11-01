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
        double a, c;
        int ta, tc;
        cin >> a >> c >> ta >> tc;
        printf("%.2lf\n", a * ta + c * tc);
    }

    return 0;
}
