#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll inf = 1LL << 62;
void floydWarshall(vector<vector<ll>>& m) {
	int n = sz(m);
	rep(i,0,n) m[i][i] = min(m[i][i], 0LL);
	rep(k,0,n) rep(i,0,n) rep(j,0,n)
		if (m[i][k] != inf && m[k][j] != inf) {
			auto newDist = max(m[i][k] + m[k][j], -inf);
			m[i][j] = min(m[i][j], newDist);
		}
	rep(k,0,n) if (m[k][k] < 0) rep(i,0,n) rep(j,0,n)
		if (m[i][k] != inf && m[k][j] != inf) m[i][j] = -inf;
}


void solve(int t) {
	int n; cin >> n;
	vector<vector<ll>> graph(n, vector<ll>(n, inf));
	vector<ll> ele(n);
	for (auto &x : ele) cin >> x;
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		string one, two; cin >> one >> two;
		int a = stoi(one.substr(1, sz(one) - 2));
		int b = stoi(two.substr(0, sz(two) - 1));
		a--; b--;
		graph[a][b] = abs(ele[a] - ele[b]);
		graph[b][a] = abs(ele[a] - ele[b]);
	}
	floydWarshall(graph);
	int k; cin >> k;
	ll dist = 0;
	if (k) {
		int start; cin >> start; start--;
		for (int i = 1; i < k; i++) {
			int next; cin >> next; next--;
			dist += graph[start][next];
			start = next;
		}
	}

	cout << "The least amount of work on trip " << t << " is: " << dist << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++)
		solve(tt);

	return 0;
}

