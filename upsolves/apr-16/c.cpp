#include <bits/stdc++.h>
using namespace std;

// #define MULTI
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct DSU {
	vi e;
	DSU(int n) : e(n, -1) {}
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool same(int a, int b) { return find(a) == find(b); }
	bool join(int a, int b) {
		if ((a = find(a)) == (b = find(b)))
			return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

void cutLeaves(vector<bool> &leaf, vector<set<int>> &adj, vector<set<int>> &rev) {
	queue<int> leafQueue;
	for (int i = 0; i < sz(adj); i++)
		if (sz(adj[i]) == 0)
			leafQueue.push(i);

	while (!leafQueue.empty()) {
		int node = leafQueue.front();
		leafQueue.pop();

		leaf[node] = true;
		for (int p : rev[node]) {
			adj[p].erase(node);
			if (sz(adj[p]) == 0)
				leafQueue.push(p);
		}
		rev[node].clear();
	}
}

void compressChains(DSU &dsu, vector<set<int>> &adj, vector<set<int>> &rev) {
	priority_queue<pii, vector<pii>, greater<pii>> chain;
	vector<bool> inQueue(sz(adj), false);
	for (int i = 0; i < sz(adj); i++)
		if (sz(adj[i]) == 1) {
			chain.emplace(sz(rev[i]), i);
			inQueue[i] = true;
		}

	while (!chain.empty()) {
		auto [_, node] = chain.top();
		chain.pop();
		inQueue[node] = false;

		int next = *begin(adj[node]);
		if (next == node) continue;
		dsu.join(node, next);

		for (int p : rev[node]) {
			adj[p].erase(node);
			adj[p].insert(next);
			rev[next].insert(p);

			if (sz(adj[p]) == 1 && !inQueue[p])
				chain.emplace(sz(rev[p]), p);
		}

		adj[node].clear();
		rev[node].clear();
		rev[next].erase(node);
	}
}

void solve(int tc) {
	int N, M; cin >> N >> M;
	vector<set<int>> adj(N), rev(N);
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		adj[a].insert(b);
		rev[b].insert(a);
	}

	vector<bool> leaf(N, false);
	cutLeaves(leaf, adj, rev);

	DSU dsu(N);
	compressChains(dsu, adj, rev);

	int Q; cin >> Q;
	for (int i = 0; i < Q; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		if (dsu.same(a, b) || leaf[a] || leaf[b])
			cout << "B";
		else cout << "H";
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int tc = 1;
#ifdef MULTI
	int t; cin >> t;
	for (; tc <= t; tc++)
#endif
		solve(tc);

    return 0;
}

