#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// Keep each node's preorder and lowlink (how high it can jump)
vector<bool> seen;
vi pre, low;
int pre_val = 0;

vector<vi> adjList;

void dfs(int v, int par) {
	// Set up normal stuff
	seen[v] = true;
	low[v] = pre_val;
	pre[v] = pre_val++;

	// For all children
	for (int c : adjList[v]) {
		if (c == par) continue;
		// If we have seen our child, and it's not our parent then draw lowlink
		if (seen[c])
			low[v] = min(low[v], pre[c]);
		else {
			dfs(c, v);
			low[v] = min(low[v], low[c]);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m; cin >> n >> m;

	// Initialize everything
	adjList = vector<vi>(n);

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	seen = vector<bool>(n, false);
	pre = vi(n, -1);
	low = vi(n, -1);

	// Lowlink
	dfs(0, -1);

	for (int i = 0; i < n; i++)
		cout << pre[i]+1 << ' ' << low[i]+1 << nl;

	return 0;
}

