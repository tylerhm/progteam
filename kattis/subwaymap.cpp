#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, l;
vector<vector<pii>> adjList;

int t;
vi tin, tout;
vector<vi> jmp, mx;

void dfs(int v, int p, int w) {
	tin[v] = ++t;
	jmp[v][0] = p;
	mx[v][0] = w;
	for (int i = 1; i <= l; ++i)
		jmp[v][i] = jmp[jmp[v][i-1]][i-1];

	for (auto [u, w] : adjList[v])
		if (u != p)
			dfs(u, v, w);

	tout[v] = ++t;
}

bool isAncestor(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int maxOnPath(int u, int v) {
	int pathMax = INT_MIN;

	for (int i = l; i >= 0; --i)
		if (!isAncestor(jmp[u][i], v))
			u = jmp[u][i], pathMax = max(pathMax, mx[u][i]);

	for (int i = l; i >= 0; --i)
		if (!isAncestor(jmp[v][i], u))
			v = jmp[v][i], pathMax = max(pathMax, mx[v][i]);

	return pathMax;
}

void preprocess(int root) {
	tin.resize(n);
	tout.resize(n);
	t = 0;

	l = __lg(n);
	if ((1 << l) != n)
		l++;

	jmp.assign(n, vi(l + 1));
	mx.assign(n, vi(INT_MIN));
	dfs(root, root, -1);

	for (int i = 0; i < n; ++i)
		for (int j = 1; j <= l; ++j)
			mx[i][j] = max(mx[i][j-1], mx[jmp[i][j-1]][j-1]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	cin >> n >> m;
	adjList.resize(n);
	set<pii> mst;

	vector<pii> unknown;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		string ls; cin >> ls;

		int c; cin >> c;
		if (c) mst.emplace(a, b), mst.emplace(b, a);

		int l = -1;
		if (ls == "?") unknown.emplace_back(a, b);
		else l = stoi(ls);

		if (c) {
			adjList[a].emplace_back(b, l);
			adjList[b].emplace_back(a, l);
		}
	}

	preprocess(0);
	for (auto p : unknown) {
		if (mst.count(p)) cout << 1 << nl;
		else {
			int a = p.first;
			int b = p.second;
			cout << maxOnPath(a, b) << nl;
		}
	}

    return 0;
}

