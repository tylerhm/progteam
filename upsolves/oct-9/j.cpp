#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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

int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, k; cin >> n >> k;
    vector<set<int>> towers(n);
    int s, e;
    for (int i = 0; i < k; i++) {
        int b, p; cin >> b >> p;
        if (i == 0) s = b;
        if (i == 1) e = b;
        towers[b].insert(p);
    }

    vector<vector<pii>> adjList(n);
    for (int i = 0; i < n; i++) {
        for (int doge : towers[i]) {
            for (int dist = 1, tower = i + doge; tower < n; tower += doge, dist++) {
                adjList[i].emplace_back(tower, dist);
                if (towers[tower].count(doge))
                    break;
            }
            for (int dist = 1, tower = i - doge; tower >= 0; tower -= doge, dist++) {
                adjList[i].emplace_back(tower, dist);
                if (towers[tower].count(doge))
                    break;
            }
        }
    }

    auto [seen, dist] = dijkstra(adjList, s);
    if (!seen[e]) cout << -1 << endl;
    else cout << dist[e] << endl;

    return 0;
}

