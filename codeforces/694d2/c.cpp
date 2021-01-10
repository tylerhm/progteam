#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n, m; cin >> n >> m;
    vector<int> friends(n);
    vector<int> presents(m);
    for (int i = 0; i < n; i++) cin >> friends[i];
    for (int i = 0; i < m; i++) cin >> presents[i];

    sort(all(friends), greater<int>());

    ll cost = 0;
    ll curPres = 0;
    for (int i = 0; i < n; i++) {
        ll pres = presents[curPres];
        ll cash = presents[friends[i]-1];
        if (pres < cash) {
            cost += pres;
            curPres++;
        }
        else
            cost += cash;
    }
    cout << cost << nl;
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
