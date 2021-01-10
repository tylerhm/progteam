#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n, m; cin >> n >> m;
    ll aS = 0, bS = 0;
    vector<int> aV(n), bV(m);
    for (int i = 0; i < n; i++) {
        cin >> aV[i];
        aS += aV[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> bV[i];
        bS += bV[i];
    }
    sort(all(aV));
    sort(all(bV), greater<int>());
    
    int moves = 0;
    while (aS <= bS) {
        if (moves == n || moves == m) {
            cout << -1 << nl;
            return;
        }
        aS += bV[moves] - aV[moves];
        bS += aV[moves] - bV[moves];
        moves++;
    }
    cout << moves << nl;
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
