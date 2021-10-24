#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (int b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), 0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (int a : btoa) if(a != -1) A[a] = -1;
		rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay++) {
			bool islast = 0;
			next.clear();
			for (int a : cur) for (int b : g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && !B[b]) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			for (int a : next) A[a] = lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		rep(a,0,sz(g))
			res += dfs(a, 0, g, btoa, A, B);
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int n; cin >> n;

	vector<vi> grid(10'000, vi(10'000, -1));
	vector<tuple<int, int, int, int>> dominos;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--, y1--, x2--, y2--;
		dominos.emplace_back(x1, y1, x2, y2);
		grid[x1][y1] = i;
		grid[x2][y2] = i;
	}

	int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
	vector<vi> adjList(n);
	map<int, pii> dominoToLeft, dominoToRight;
	for (int i = 0; i < 10'000; i++) {
		for (int j = 0; j < 10'000; j++) {
			int domino = grid[i][j];
			if (domino == -1) continue;

			if ((i + j) & 1) {
				dominoToRight[domino] = {i, j};
				continue;
			}

			dominoToLeft[domino] = {i, j};

			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || nx >= 10'000 || ny < 0 || ny >= 10'000) continue;

				int adj = grid[nx][ny];
				if (adj == -1 || adj == domino) continue;

				adjList[domino].push_back(adj);
			}
		}
	}

	vi par(n, -1);
	hopcroftKarp(adjList, par);

	// check invalid
	for (int v : par) if (v == -1) {
		cout << "impossible" << endl;
		return 0;
	}

	for (int i = 0; i < sz(par); i++) {
		auto rightLoc = dominoToRight[i];
		auto leftLoc = dominoToLeft[par[i]];
		grid[leftLoc.first][leftLoc.second] = i;
		grid[rightLoc.first][rightLoc.second] = i;
	}

	for (auto [x1, x2, y1, y2] : dominos)
		cout << grid[x1][x2] << ' ' << grid[y1][y2] << endl;

    return 0;
}

