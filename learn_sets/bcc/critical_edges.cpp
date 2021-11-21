#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

vector<pii> cuts;
void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                cuts.emplace_back(min(v, to), max(v, to));
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
	cuts.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }

	sort(all(cuts));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		int m; cin >> n >> m;
		adj.assign(n, vi(0));
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		find_bridges();
		cout << "Caso #" << tt << nl;
		if (!sz(cuts)) {
			cout << "Sin bloqueos" << nl;
			continue;
		}
		cout << sz(cuts) << nl;
		for (auto p : cuts) {
			auto &u = p.first;
			auto &v = p.second;
			cout << u+1 << ' ' << v+1 << nl;
		}
	}

	return 0;
}

