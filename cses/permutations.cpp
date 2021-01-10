#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n; cin >> n;

    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    if (n == 4) {
        cout << "2 4 1 3\n";
        return 0;
    }

    if (n <= 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    for (ll i = 1; i <= n; i+=2) cout << i << " ";
    for (ll i = 2; i <= n; i+=2) cout << i << " ";
    cout << "\n";

    return 0;
}
