#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T, class F>
struct TreeQueries {
	vector<vector<pair<int, T>>> adj;
	F f; T le; // any associative function and least val
	int n, l;
	vector<vi> jmp, assoc; vi dep;
	TreeQueries(vector<vector<pair<int, T>>> &adj, F f, T le, int root=0) :
	adj(adj), f(f), le(le), n(sz(adj)) {
		l = ceil(log2(n));
		jmp.assign(l+1, vi(n));
		assoc.assign(l+1, vi(n, le));
		dep.resize(n);
		dfs(root, root, le, 0);
	}
	void dfs(int v, int p, int w, int d) {
		dep[v] = d;
		jmp[0][v] = p;
		assoc[0][v] = w;
		for (int lg = 1; lg <= l; ++lg) {
			jmp[lg][v] = jmp[lg-1][jmp[lg-1][v]];
			assoc[lg][v] = f(assoc[lg-1][v], assoc[lg-1][jmp[lg-1][v]]);
		}
		for (auto &[u, w] : adj[v]) if (u != p)
			dfs(u, v, w, d+1);
	}
	pair<int, T> query(int u, int v) { // returns {lca, pathlen}
		if (dep[u] > dep[v]) swap(u, v);
		int lft = dep[v] - dep[u];
		T path = le;
		for (int lg = 0; lft; ++lg, lft >>= 1)
			if (lft & 1) {
				path = f(path, assoc[lg][v]);
				v = jmp[lg][v];
			}
		if (u == v) return {u, path};
		for (int lg = l; lg >= 0; lg--)
			if (jmp[lg][v] != jmp[lg][u]) {
				path = f(path, f(assoc[lg][v], assoc[lg][u]));
				v = jmp[lg][v]; u = jmp[lg][u];
			}
		path = f(path, f(assoc[0][v], assoc[0][u]));
		return {jmp[0][v], path};
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int h, w;
	cin >> h >> w;

	vector<string> grid(h + 1);
	for (auto & x : grid) {
		if (cin.peek() == '\n')
			cin.ignore();
		getline(cin, x);
	}

	vector<vector<pair<int, int>>> tree(h * w);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j < 2 * w + 1; j += 2) {

			auto addEdge = [&](int v, int u) {
				tree[v].emplace_back(u, 1);
			};

			int di = i - 1;
			int dj = j / 2;
			int v = di * w + dj;

			// up
			if (di - 1 >= 0 && di - 1 < h && grid[i - 1][j] == ' ') {
				int u = (di - 1) * w + dj;
				addEdge(v, u);
			}
			// down
			if (grid[i][j] == ' ') {
				int u = (di + 1) * w + dj;
				addEdge(v, u);
			}
			// left
			if (dj - 1 >= 0 && dj - 1 < w && grid[i][j - 1] == ' ') {
				int u = di * w + dj - 1;
				addEdge(v, u);
			}
			// right
			if (dj + 1 >= 0 && dj + 1 < w && grid[i][j + 1] == ' ') {
				int u = di * w + dj + 1;
				addEdge(v, u);
			}
		}
	}

	TreeQueries<int, function<int(int, int)>> t(
		tree, [](const int a, const int b) { return a + b; }, 0);

	int m;
	cin >> m;
	long long int tot = 0;
	int sx, sy;
	cin >> sx >> sy;
	m--;
	sx--, sy--;
	int v = sx * w + sy;
	while (m--) {
		int ex, ey;
		cin >> ex >> ey;
		ex--, ey--;

		int u = ex * w + ey;
		tot += t.query(v, u).second;

		v = u;
	}

	cout << tot << endl;

	return 0;
}
