#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    ll n, x; cin >> n >> x;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        if (val <= x)
            sum -= 2*val;
    }
    sum += x*(x+1)/2;
    cout << sum << nl;
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
