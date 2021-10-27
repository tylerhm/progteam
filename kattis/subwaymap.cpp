#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int n, m; cin >> n >> m;
	vector<vector<pii>> adjList;
	set<pii> mst;
	map<int, int> nodeToMst;

	vector<pii> unknown;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		string ls; cin >> ls;
		int c; cin >> c;
		if (c) mst.emplace(a, b);

		int l = -1;
		if (ls == "?") unknown.emplace_back(a, b);
		else l = stoi(ls);

		adjList[a].emplace_back(b, l);
	}

	for (auto p : unknown) {
		if (mst.count(p)) cout << 1 << nl;
		else {
			int a = p.first;
			int b = p.second;


		}
	}

    return 0;
}

