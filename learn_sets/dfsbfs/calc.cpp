#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
#define MOD 1000000
int oo = -1^1<<31;
using namespace std;

void solve(int tc) {
    int a, b, c, t; cin >> a >> b >> c >> t;
    
    vector<bool> visited(MOD);
    vector<int> dist(MOD, -1);
    queue<int> bfs;
    bfs.push(0);
    visited[0] = true;
    dist[0] = 0;

    while (!bfs.empty()) {
        int curVal = bfs.front();
        bfs.pop();
        vector<int> options;
        options.push_back((curVal + a) % MOD);
        options.push_back((curVal * b) % MOD);
        options.push_back((curVal / c) % MOD);

        bool ans = false;
        for (int o : options) {
            if (o == t)
                ans = true;
            if (visited[o]) continue;
            visited[o] = true;
            dist[o] = dist[curVal] + 1;
            bfs.push(o);
        }
        if (ans)
            break;
    }
    cout << dist[t] << nl;
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
