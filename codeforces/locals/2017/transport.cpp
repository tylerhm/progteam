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

map<string, int> transport;

void solve() {
    int c; cin >> c;
    // construct a graph with 4*c nodes
    vector<vector<pair<int, ll>>> adjList(4*c);

    // {name, index}
    map<string, int> cities;

    for (int i = 0; i < c; i++) {
        string name; cin >> name;
        int changeCost; cin >> changeCost;

        cities[name] = i;

        // connect nodes [i*4, i*4 + 3] together with cost
        int node = i*4;
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                if (j != k)
                    adjList[node+j].push_back({node+k, changeCost});
    }

    int r; cin >> r;
    for (int i = 0; i < r; i++) {
        string from, to, mode;
        cin >> from >> to >> mode;

        int u = cities[from]*4;
        int v = cities[to]*4;
        int add = transport[mode];

        int cost; cin >> cost;
        adjList[u+add].push_back({v+add, cost});
        adjList[v+add].push_back({u+add, cost});
    }

    string source, dest; cin >> source >> dest;
    int s = cities[source]*4;
    int d = cities[dest]*4;

    ll bestDist = LLONG_MAX;
    for (int i = 0; i < 4; i++) {
        auto res = dijkstra(adjList, s+i);
        auto seen = res.first;
        auto dist = res.second;

        for (int j = 0; j < 4; j++)
            if (seen[d+j])
                bestDist = min(bestDist, dist[d+j]);
    }

    cout << bestDist << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    transport["AIR"] = 0;
    transport["SEA"] = 1;
    transport["RAIL"] = 2;
    transport["TRUCK"] = 3;

    int n; cin >> n;
    for (int i = 0; i < n; i++)
        solve();

    return 0;    
}
