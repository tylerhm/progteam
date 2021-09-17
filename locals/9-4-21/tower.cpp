#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, k;
vector<vector<pair<int, ll>>> adjList;

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

ll time(ll x1, ll x2, ll y1, ll y2) {
    return abs(x1 - x2) + (y1 - y2)*(y1 - y2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> n >> k;
    vector<ll> layers(n);
    for (auto &x : layers) cin >> x;

    adjList = vector<vector<pair<int, ll>>>(n);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i + j >= n) break;
            adjList[i].emplace_back(i + j, time(layers[i], layers[i + j], i, i + j));
        }
    }

    auto res = dijkstra(adjList, 0);
    cout << res.second[n-1] << endl;

    return 0;    
}
