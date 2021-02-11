#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

bool bfs(vector<vector<int>> adjList, pair<int, int> badEdge) {
	queue<int> q;
	vector<bool> visited(adjList.size(), false);
	q.push(0);
	visited[0] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adjList[u]) {
			if (visited[v] || (u == badEdge.first && v == badEdge.second)) continue;
			q.push(v);
			visited[v] = true;
		}
	}
	return visited[adjList.size()-1];
}

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> adjList(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	pair<int, int> badEdge;
	for (int u = 0; u < n; u++) {
		for (int v : adjList[u]) {
			badEdge = {u, v};
			if (!bfs(adjList, badEdge)) {
				cout << "Halt, Spiderman! Plans Thwarted!" << nl;
				return;
			}
		}
	}
	cout << "How Sad, Perpetrator Triumphed" << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int tt; cin >> tt;
	for (int t = 0; t < tt; t++)
		solve();

    return 0;
}
