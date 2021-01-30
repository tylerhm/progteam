#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

template <class T>
pair<vector<bool>, vector<T>> dijkstra(
 const vector<vector<pair<int, T>>>& adj, int s) {
  using ST = pair<T, int>; /// state type
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

template <class T>
pair<vector<bool>, vector<T>> dijkstraGreater(
 const vector<vector<pair<int, T>>>& adj, int s) {
  using ST = pair<T, int>; /// state type
  priority_queue<ST, vector<ST>, greater<ST>> q;
  vector<T> dist(adj.size());
  vector<bool> seen(adj.size());
  q.emplace(T{}, s);
  seen[s] = 1;
  while (!q.empty()) {
    auto [d, u] = q.top();
    q.pop();
    if (dist[u] > d) continue;
    for (auto [v, w] : adj[u])
      if (!seen[v] || d + w > dist[v]) {
        q.emplace(dist[v] = d + w, v);
        seen[v] = 1;
      }
  }
  return {seen, dist};
}

void solve(int t) {
    int v, e; cin >> v >> e;
    vector<vector<pair<int, ll>>> adjList(v);
    for (int i = 0; i < e; i++) {
        ll s, d, m; cin >> s >> d >> m;
        adjList[s].push_back({d, m});
    }
    auto s = dijkstra(adjList, 0);
    auto l = dijkstraGreater(adjList, 0);
    cout << s.second[v-1] << ' ' << l.second[v-1] << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int c; cin >> c;
    for (int i = 0; i < c; i++) {
        solve(c);
    }

    return 0;
}
