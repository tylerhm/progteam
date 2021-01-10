#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n; cin >> n;
    int curVal, mult, base = 2;
    for (int i = 0; i < n/4; i++) {
        curVal = 0;
        mult = 8;
        for (int j = 0; j < 4; j++) {
            char c; cin >> c;
            curVal += mult * (c-'0');
            mult /= base;
        }
        cout << (char)('a' + curVal);
    }
    cout << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tt; cin >> tt;
    for (int t = 1; t <= tt; t++)
        solve(t);

    return 0;
}
