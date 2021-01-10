#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n, k; cin >> n >> k;
    vector<int> ground(n);
    for (int i = 0; i < n; i++) cin >> ground[i];
    for (int i = 1; i < n; i++) {
        if (ground[i] >= ground[i-1]+2*k-1 || ground[i] <= ground[i-1]-2*k+1) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
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
