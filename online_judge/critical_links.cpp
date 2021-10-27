#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int t;
vector<vi> adjList;
vector<bool> visited;
vector<string> links;
vi pre, low;

void dfs(int u, int p) {
	visited[u] = true;
	pre[u] = low[u] = t++;
	for (int v : adjList[u]) {
		if (v == p) continue;
		if (visited[v])
			low[u] = min(low[u], pre[v]);
		else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > pre[u])
				links.push_back(to_string(u) + " - " + to_string(v));
		}
	}
}

void getLinks() {
	visited.resize(sz(adjList), false);
	links = vector<string>();
	pre.resize(sz(adjList), -1);
	low.resize(sz(adjList), -1);
	t = 0;
	for (int u = 0; u < sz(adjList); u++) {
		if (visited[u]) continue;
		dfs(u, -1);
	}
	sort(all(links));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	while (cin >> n) {
		adjList.resize(n);

		for (int i = 0; i < n; i++) {
			int id; cin >> id;
			string parenNum; cin >> parenNum;
			for (int j = 0; j < stoi(parenNum.substr(1, sz(parenNum) - 2)); j++) {
				int connection; cin >> connection;
				adjList[id].push_back(connection);
			}
		}

		getLinks();
		cout << sz(links) << " critical links" << nl;
		for (string s : links) cout << s << nl;
		cout << nl;
	}

	return 0;
}

