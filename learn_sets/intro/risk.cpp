#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int c; cin >> c;
    
    vector<int> a, d, nd;
    vector<bool> du;
    while (c--)
    {
        int n; cin >> n;
        a = vector<int>(n);
        d = vector<int>(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> d[i];

        sort(a);
        sort(d);

        int di = n - 1, ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (d[di] >= a[i])
            {
                ans++;
                di--;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
