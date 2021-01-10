#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int a, b, c; cin >> a >> b >> c;
    ll sum = a+b+c;
    if (sum % 9 == 0 && min(a, min(b, c)) >= sum/9) cout << "YES";
    else cout << "NO";
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
