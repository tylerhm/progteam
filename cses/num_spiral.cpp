#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> y >> x;
        
        if (x >= y) {
            if (x&1) cout << (x*x-(y-1));
            else cout << (x+(y-1));
        }
        else {
            if (y&1) cout << (y+(x-1));
            else cout << (y*y-(x-1));
        }
        cout << "\n";
    }

    return 0;
}
