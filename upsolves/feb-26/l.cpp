#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <list>
#include <numeric>
#include <random>
#include <tuple>
#include <map>
#include <set>
#include <stack>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct PushRelabel {
	struct Edge {
		int dest, back;
		ll f, c;
	};
	vector<vector<Edge>> g;
	vector<ll> ec;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

	void addEdge(int s, int t, ll cap, ll rcap=0) {
		if (s == t) return;
		g[s].push_back({t, sz(g[t]), 0, cap});
		g[t].push_back({s, sz(g[s])-1, 0, rcap});
	}

	void addFlow(Edge& e, ll f) {
		Edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	ll calc(int s, int t) {
		int v = sz(g); H[s] = v; ec[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i,0,v) cur[i] = g[i].data();
		for (Edge& e : g[s]) addFlow(e, e.c);

		for (int hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -ec[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while (ec[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + sz(g[u])) {
					H[u] = 1e9;
					for (Edge& e : g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						rep(i,0,v) if (hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
					addFlow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
	bool leftOfMinCut(int a) { return H[a] >= sz(g); }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int N, K; cin >> N >> K;
    map<pii, int> edgeID;
    vector<vi> edgeMaterials(N);
    vector<vi> adj(N);
    vi par(N);
    for (int u = 0; u < N; u++) {
        int v; cin >> v; v--;
        par[u] = v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edgeID[minmax(u, v)] = u;

        int m; cin >> m;
        for (int i = 0; i < m; i++) {
            int mat; cin >> mat;
            edgeMaterials[u].push_back(mat);
        }
    }

    vi workers(K);
    for (auto &x : workers)
        cin >> x;

    stack<int> st;
    set<int> cycle;

    auto popCycle = [&](int target) {
        int last = target, x;
        do {
            x = st.top();
            cycle.insert(edgeID[minmax(x, last)]);
            st.pop();
            last = x;
        } while (x != target);
    };

    vector<bool> visited(N, false);
    bool done = false;
    auto dfs = [&](int u, int par, auto &&dfs) -> void {
        for (auto v : adj[u]) if (v != par) {
            if (visited[v]) {
                popCycle(v);
                done = true;
                return;
            }

            visited[v] = true;
            st.push(v);
            dfs(v, u, dfs);
            if (done) return;
            st.pop();
        }
    };

    visited[0] = true;
    st.push(0);
    dfs(0, -1, dfs);

    int nodes = N + K + 1 + 2;
    int cycleRestrictor = nodes - 3;
    int s = nodes - 2, t = nodes - 1;
    PushRelabel flow(nodes);

    // Bridges
    for (int i = 0; i < N; i++) {
        if (cycle.count(i)) continue;
        flow.addEdge(s, i, 1);
    }

    // Cycle
    flow.addEdge(s, cycleRestrictor, sz(cycle) - 1);
    for (int u : cycle)
        flow.addEdge(cycleRestrictor, u, 1);

    for (int i = 0; i < N; i++) {
        set<int> validWorkers;
        for (int mat : edgeMaterials[i])
            for (int w = 0; w < K; w++)
                if (workers[w] == mat)
                    validWorkers.insert(w);

        for (int w : validWorkers)
            flow.addEdge(i, N + w, 1);
    }

    for (int i = 0; i < K; i++)
        flow.addEdge(N + i, t, 1);

    if (flow.calc(s, t) != N - 1) {
        cout << -1 << "\n";
        return 0;
    }

    vector<pii> ans(K, {0, 0});
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < sz(flow.g[i]); j++) {
            if (flow.g[i][j].f == 1) {
                ans[flow.g[i][j].dest - N] = {i+1, par[i]+1};
                break;
            }
        }
    }
    for (auto [x, y] : ans)
        cout << x << ' ' << y << "\n";

    return 0;
}

