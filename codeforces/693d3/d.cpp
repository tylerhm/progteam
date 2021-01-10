#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n; cin >> n;
    priority_queue<int> vals;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        vals.push(v);
    }
    int curTurn = 0;
    ll aS = 0, bS = 0;
    while (!vals.empty()) {
        int next = vals.top();
        vals.pop();

        if (curTurn&1) {
            if (next&1) bS+=next;
        }
        else if (!(next&1)) aS+=next;

        curTurn++;
    }
    if (aS==bS) cout << "Tie";
    else if (aS>bS) cout << "Alice";
    else cout << "Bob";
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
