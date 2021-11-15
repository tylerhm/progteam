#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;
        ll flow() { return max(oc - c, 0LL); } // if you need flows
    };
    vi lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
    void addEdge(int a, int b, ll c, ll rcap = 0) {
        adj[a].push_back({b, sz(adj[b]), c, c});
        adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
    }
    ll dfs(int v, int t, ll f) {
        if (v == t || !f) return f;
        for (int& i = ptr[v]; i < sz(adj[v]); i++) {
            Edge& e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
                if (ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }
    ll calc(int s, int t) {
        ll flow = 0; q[0] = s;
        rep(L,0,31) do { // 'int L=30' maybe faster for random data
            lvl = ptr = vi(sz(q));
            int qi = 0, qe = lvl[s] = 1;
            while (qi < qe && !lvl[t]) {
                int v = q[qi++];
                for (Edge e : adj[v])
                    if (!lvl[e.to] && e.c >> (30 - L))
                        q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
            }
            while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
        } while (lvl[t]);
        return flow;
    }
    bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

void solve(int tt) {
    int n; cin >> n;
    double maxJump; cin >> maxJump;

    typedef pair<double, double> pdd;
    auto canJump = [&](pdd &a, pdd &b) -> bool {
        double dx = abs(a.first - b.first);
        double dy = abs(a.second - b.second);
        double dist = sqrt(dx*dx + dy*dy);
        return dist <= maxJump;
    };

    int totalPenguins = 0;
    vector<vi> adj(n);
    vector<tuple<pdd, int, int>> bergs(n);
    for (int i = 0; i < n; i++) {
        auto &[p, n, m] = bergs[i];
        cin >> p.first >> p.second >> n >> m;
        totalPenguins += n;
        for (int j = i - 1; j >= 0; j--) {
            if (canJump(get<0>(bergs[i]), get<0>(bergs[j]))) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // Sources will always be penguins
    // Make every node the sink to test
    // Connections out go to a funnel node and then the rest
    bool found = false;
    int s = 2*n;
    for (int t = 0; t < n; t++) {
        Dinic flow(2*n + 1);
        for (int i = 0; i < n; i++) {
            if (i == t) continue;
            flow.addEdge(s, 2*i, get<1>(bergs[i]));
            flow.addEdge(2*i, 2*i+1, get<2>(bergs[i]));
            for (int j : adj[i])
                flow.addEdge(2*i+1, 2*j, 1e9);
        }
        if (flow.calc(s, t) == n-get<1>(bergs[t])) {
            found = true;
            cout << t << ' ';
        }
    }
    if (!found) cout << -1;
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
        solve(tt);

    return 0;
}

