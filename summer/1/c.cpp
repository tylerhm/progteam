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

void solve() {
    int n; cin >> n;
    vector<vector<pair<int, int>>> adjList(n * 2 + 2);

    int l0, l1, s0, s1; cin >> l0 >> l1 >> s0 >> s1;

    adjList[0].push_back({1, l0});
    adjList[0].push_back({2, l1});

    rep(i, 1, n) {
        int val; cin >> val; 
        adjList[i*2 - 1].push_back({(i+1)*2, val});
    }

    rep(i, 1, n) {
        int val; cin >> val; 
        adjList[i*2 - 1].push_back({(i+1)*2 - 1, val});
    }

    rep(i, 1, n) {
        int val; cin >> val; 
        adjList[i*2].push_back({(i+1)*2 - 1, val});
    }

    rep(i, 1, n) {
        int val; cin >> val; 
        adjList[i*2].push_back({(i+1)*2, val});
    }

    adjList[n*2 - 1].push_back({n*2 + 1, s0});
    adjList[n*2].push_back({n*2 + 1, s1});

    auto ans = dijkstra(adjList, 0);

    cout << ans.second[n*2 + 1] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int i = 0; i < t; i++) solve();

    return 0;    
}
