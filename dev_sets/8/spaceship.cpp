#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n_cases; cin >> n_cases;
    for (int iter = 1; iter <= n_cases; iter++)
    {
        int x, y, z, e; cin >> x >> y >> z >> e;
        int cnt = 0;
        for (int i = 0; i < e; i++) {
            int bx, by, bz, d; cin >> bx >> by >> bz >> d;
            double dist = sqrt((x-bx)*(x-bx)+(y-by)*(y-by)+(z-bz)*(z-bz));
            if (d >= dist) cnt++;
        }
        cout << "You will be picked up by " << cnt << " radars.\n";
    }
    return 0;
}
