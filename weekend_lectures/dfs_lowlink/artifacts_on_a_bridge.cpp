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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int N, M; cin >> N >> M;

	vector<vector<pii>> adjList(N);
	for (int i = 0; i < M; i++) {
		int a, b, artifact; cin >> a >> b >> artifact;
		a--, b--;
		adjList[a].emplace_back(b, artifact);
		adjList[b].emplace_back(a, artifact);
	}

	int curPre = 0;
	vi pre(N, -1), low(N, -1);
	vi stck;
	int ncomps = 0;
	vi comp(N);
	auto lowLink = [&](int u, int par, auto &&lowLink) -> void {
		pre[u] = low[u] = curPre++;
		stck.push_back(u);

		for (auto [v, artifact] : adjList[u]) {
			if (v == par) continue;
			// Forward edge
			if (pre[v] == -1) {
				lowLink(v, u, lowLink);
				low[u] = min(low[u], low[v]);

				// u -> v is a bridge
				if (pre[v] == low[v]) {
					int x;
					do {
						x = stck.back();
						stck.pop_back();
						comp[x] = ncomps;
					} while (x != v);
					ncomps++;
				}
			}
			// Back edge
			else {
				low[u] = min(low[u], pre[v]);
			}
		}
	};

	lowLink(0, -1, lowLink);
	while (sz(stck)) {
		int x = stck.back();
		stck.pop_back();
		comp[x] = ncomps;
	}
	ncomps++;

	vector<vector<pii>> meta(ncomps);
	vector<bool> metaArtifact(ncomps, false);
	for (int u = 0; u < N; u++) {
		for (auto [v, artifact] : adjList[u]) {
			if (comp[u] != comp[v])
				meta[comp[u]].emplace_back(comp[v], artifact);
			else if (artifact)
				metaArtifact[comp[u]] = true;
		}
	}

	int a, b; cin >> a >> b;
	a--, b--;
	a = comp[a], b = comp[b];
	auto dfs = [&](int u, int par, bool hasArtifact, auto &&dfs) -> bool {
		if (metaArtifact[u]) hasArtifact = true;
		if (u == b) return hasArtifact;

		for (auto [v, artifact] : meta[u]) {
			if (v == par) continue;
			if (dfs(v, u, hasArtifact || artifact, dfs))
				return true;
		}

		return false;
	};

	cout << (dfs(a, -1, metaArtifact[a], dfs) ? "YES" : "NO") << endl;
    return 0;
}

