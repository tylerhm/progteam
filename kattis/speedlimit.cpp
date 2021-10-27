#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n; cin >> n;
    while (n != -1)
    {
        int ans = 0;
        int tt = 0;
        for (int i = 0; i < n; i++)
        {
            int s, t; cin >> s >> t;
            t -= tt;
            tt += t;
            ans += s * t;
        }
        cout << ans << " miles\n";
        cin >> n;
    }
    return 0;
}
