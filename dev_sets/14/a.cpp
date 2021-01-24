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

void solve(int n) {
    FordFulkerson flow = FordFulkerson(52);
    // connect source and sink
    for (int i = 0; i < 26; i++) {
        flow.conS(i, 1);
        flow.conT(26+i, 1);
    }

    // connect letters
    set<pair<char, char>> seen;
    for (int i = 0; i < n; i++) {
        string first, last; cin >> first >> last;
        char f = first[0], l = last[0];
        if (seen.insert(make_pair(f, l)).second)
            flow.add(first[0]-'A', 26+last[0]-'A', 1);
    }
    cout << flow.ff() << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    while (n != 0) {
        solve(n);
        cin >> n;
    }

    return 0;
}
