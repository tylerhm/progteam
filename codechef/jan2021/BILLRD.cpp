#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n; cin >> n;
    int k; cin >> k;
    int x, y; cin >> x >> y;
    
    if (x==y) cout << n << ' ' << n << nl;
    else {
        vector<pair<int, int>> possCollide(4);
        if (x < y) {
            possCollide[0] = {x+n-y, n};
            possCollide[1] = {n, x+n-y};
            possCollide[2] = {y-x, 0};
            possCollide[3] = {0, y-x};
        }
        else {
            possCollide[0] = {n, y+n-x};
            possCollide[1] = {y+n-x, n};
            possCollide[2] = {0, x-y};
            possCollide[3] = {x-y, 0};
        }
        int collision = (k-1)%4;
        cout << possCollide[collision].first << ' ' << possCollide[collision].second << nl;
    }
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
