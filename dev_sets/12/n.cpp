#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int m, n; cin >> m >> n;
    // fermat's last theorem
    // no x^n + y^n = z^n for any n greater than 2
    // return size of set where n == 2
    int count = 0;
    for (int x = 3; x <= m; x++)
        for (int y = x; y <= m; y++)
            for (int z = y; z <= m; z++) 
                if (x*x+y*y==z*z)
                    count++;
    cout << count+(m+1)*(n-1) << nl;

    return 0;
}
