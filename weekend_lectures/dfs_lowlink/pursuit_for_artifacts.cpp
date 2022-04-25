#include <iostream>
#include <queue>
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

vi num;
vector<vector<pii>> ed;
vector<bool> bridge, arts;
int Time, bridges;
template<class F>
int dfs(int at, int par, F& f) {
	int me = num[at] = ++Time, e, y, top = me;
	for (auto pa : ed[at]) if (pa.second != par) {
		tie(y, e) = pa;
		if (num[y]) {
			top = min(top, num[y]);
		} else {
			int up = dfs(y, e, f);
			top = min(top, up);
			if (up == me) {}
			else if (up < me) {}
			else { bridge[e] = true; bridges++; }
		}
	}
	return top;
}

template<class F>
void bicomps(F f) {
	num.assign(sz(ed), 0);
	rep(i,0,sz(ed)) if (!num[i]) dfs(i, -1, f);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int N, M; cin >> N >> M;
	int eid = 0; ed.resize(N);
	bridges = 0; bridge.resize(N);
	arts.resize(M);
	for (int i = 0; i < M; i++) {
		int a, b, art; cin >> a >> b >> art;
		a--; b--;
		arts[eid] = art;
		ed[a].emplace_back(b, eid);
		ed[b].emplace_back(a, eid++);
	}

	bicomps([&](const vi &edgeList){});

	// Meta graph is a tree
	vector<vector<pii>> condensed(bridges + 1);
	vector<bool> condensedArts(bridges + 1, false);
	vector<bool> condensedEdgeArts(bridges, false);

	vi comp(N, -1);
	int ncomps = 0;
	eid = 0;
	for (int i = 0; i < N; i++) {
		if (comp[i] != -1) continue;

		queue<int> bfs;
		bfs.push(i);
		comp[i] = ncomps;
		while (!bfs.empty()) {
			int cur = bfs.front();
			bfs.pop();

			for (auto [v, e] : ed[cur]) {
				if (bridge[e]) {
					if (comp[v] != -1) {
						int a = comp[cur];
						int b = comp[v];
						if (arts[e]) condensedEdgeArts[eid] = true;
						condensed[a].emplace_back(b, eid);
						condensed[b].emplace_back(a, eid++);
					}
					continue;
				}

				if (comp[v] == -1) {
					if (arts[e]) condensedArts[ncomps] = true;
					comp[v] = ncomps;
					bfs.push(v);
				} else if (comp[v] == comp[cur])
					if (arts[e]) condensedArts[ncomps] = true;
			}
		}

		ncomps++;
	}

	int a, b; cin >> a >> b;
	a--; b--;
	int start = comp[a], dealer = comp[b];

	if (start == dealer) {
		cout << (condensedArts[start] ? "YES" : "NO") << nl;
		return 0;
	}

	vector<bool> visited(sz(condensed), false);
	queue<pair<int, bool>> bfs;
	bfs.emplace(start, condensedArts[start]);
	visited[start] = true;
	while (!bfs.empty()) {
		auto [cur, art] = bfs.front();
		bfs.pop();

		for (auto [v, e] : condensed[cur]) {
			if (visited[v]) continue;
			visited[v] = true;
			bool newArtStatus = art | condensedEdgeArts[e] | condensedArts[v];
			if (v == dealer) {
				cout << (newArtStatus ? "YES" : "NO") << nl;
				return 0;
			}

			bfs.emplace(v, newArtStatus);
		}
	}

	cout << "NO" << nl;

	return 0;
}

