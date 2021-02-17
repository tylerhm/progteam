#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

struct FordFulkerson {
	vector<vector<int>> cap;  vector<bool> vis;  int n, s, t, oo = (int)(1E9);
	FordFulkerson(int size) { n = size + 2;  s = n - 2;  t = n - 1;  cap = vector<vector<int>>(n, vector<int>(n, 0)); }
	void add(int v1, int v2, int c) {  cap[v1][v2] = c;  }
    void conS(int v, int c) { cap[s][v] = c; }
    void conT(int u, int c) { cap[u][t] = c; }
	int ff() {
		vis = vector<bool>(n, false);  int f = 0;
		while (true) {
			fill(all(vis), false);  int res = dfs(s, oo);
			if (res == 0) { break; }  f += res;
		}
		return f;
	}
	int dfs(int pos, int minRes) {
		if (pos == t)  return minRes;
		if (vis[pos])  return 0;
		vis[pos] = true;  int f = 0;
		for (int i = 0; i < n; i++) {
			if (cap[pos][i] > 0)  f = dfs(i, min(cap[pos][i], minRes));
			if (f > 0) { cap[pos][i] -= f;  cap[i][pos] += f;  return f; }
		}
		return 0;
	}
};

double pairDist(pair<ll, ll> a, pair<ll, ll> b) {
    ll dx = a.first-b.first, dy = a.second-b.second;
    return sqrt(dx*dx + dy*dy);
}

void solve() {

    if (n == 1) {
        cout << 1 << nl;
        return;
    }

    vector<pair<ll, ll>> points(n);
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        points[i].first = x;
        points[i].second = y;
    }

    // build graph
    matrix = vector<vector<bool>>(n+10, vector<bool>(n+10, false));
    int edges = 0;
    for (int i = 0; i < points.size(); i++) {
        for (int j = i+1; j < points.size(); j++) {
            if (i == j) continue;
            if (pairDist(points[i], points[j]) < 1.3) {
                connect(i, j);
                edges++;
            }
        }
    }

    cout << n - findMinCover(n, edges) << nl;
}

int getInput() {
    int n;
    if (!(cin >> n))
        return -1;
    return n;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n;
    while ((n = getInput()) != -1)
        solve(n); 

    return 0;
}
