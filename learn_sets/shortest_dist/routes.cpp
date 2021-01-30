#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

template <class T>
pair<vector<bool>, vector<T>> dijkstra(
 const vector<vector<pair<int, T>>>& adj, int s) {
    using ST = pair<T, int>;
    priority_queue<ST, vector<ST>, greater<ST>> q;
    vector<T> dist(adj.size());
    vector<bool> seen(adj.size());
    q.emplace(T{}, s);
    seen[s] = 1;
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (dist[u] < d) continue;
        for (auto [v, w] : adj[u])
            if (!seen[v] || d + w < dist[v]) {
                q.emplace(dist[v] = d + w, v);
                seen[v] = 1;
            }
    }
    return {seen, dist};
}

void solve(int t) {
    int n, m, q; cin >> n >> m >> q;
    vector<vector<pair<int, ll>>> adjList(n);
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        u--; v--;
        adjList[u].emplace_back(v, c);
        adjList[v].emplace_back(u, c);
    }
    auto dist = dijkstra(adjList, 0).second;
    for (int i = 0; i < q; i++) {
        int p; cin >> p;
        p--;
        cout << dist[p] << nl;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tt; cin >> tt;
    for (int t = 0; t < tt; t++)
        solve(t);

    return 0;
}
