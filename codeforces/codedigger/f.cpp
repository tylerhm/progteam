#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

int MOD;

int gcdExtended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0
        *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int modInverse(int a) {
    int x, y;
    int g = gcdExtended(a, MOD, &x, &y);
    if (g != 1) {
        cout << "mod inverse broke" << nl;
        return -1;
    }
    x = (x % MOD + MOD) % MOD;
}

void solve(int t) {

}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 0; tt < t; tt++)
        solve(tt);

    return 0;
}
