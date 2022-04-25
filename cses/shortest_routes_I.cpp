#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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

int nxt() {
	int x; cin >> x;
	return x;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int N, M; cin >> N >> M;
	vector<vector<pair<int, ll>>> adj(N);
	for (int i = 0; i < M; i++) {
		int a, b, w; cin >> a >> b >> w;
		adj[a-1].emplace_back(b-1, w);
	}

	auto res = dijkstra(adj, 0);
	for (auto d : res.second)
		cout << d << " ";

    return 0;
}

