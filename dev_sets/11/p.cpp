#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m; cin >> n >> m;
    vector<vector<int>> adjList(n);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adjList[u-1].push_back(v-1);
    }

    queue<pair<int, int>> q;
    vector<bool> visited(n, false);
    q.emplace(0, 0);
    visited[0] = true;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (int v : adjList[u.first]) {
            if (v == n - 1) {
                cout << u.second << endl;
                return 0;
            }
            if (visited[v]) continue;

            visited[v] = true;
            q.emplace(v, u.second + 1);
        }
    }

    return 0;
}
