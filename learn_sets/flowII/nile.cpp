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
    cout << "Case #" << tt << ": ";

    int w, h, b; cin >> w >> h >> b;
    vector<vector<bool>> river(h, vector<bool>(w, true));
    for (int i = 0; i < b; i++) {
        int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
        for (int y = y0; y <= y1; y++)
            for (int x = x0; x <= x1; x++)
                river[y][x] = false;
    }

    int DR[] = {1, 0, -1, 0}, DC[] = {0, 1, 0, -1};
    auto getIdx = [&](int row, int col) -> int {
        return 2 * (row * w + col);
    };

    Dinic flow(2*w*h + 2);
    int s = 2*w*h, t = s + 1;
    for (int col = 0; col < w; col++) {
        int bot = getIdx(h-1, col);
        int top = getIdx(0, col);
        if (river[h-1][col]) flow.addEdge(s, bot, 1);
        if (river[0][col]) flow.addEdge(top, t, 1);
    }
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            int idx = getIdx(row, col);
            flow.addEdge(idx, idx+1, 1);
            for (int d = 0; d < 4; d++) {
                int nr = row + DR[d];
                int nc = col + DC[d];
                if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
                    int con = getIdx(nr, nc);
                    if (river[nr][nc]) flow.addEdge(idx+1, con, 1);
                }
            }
        }
    }

    cout << flow.calc(s, t) << nl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
        solve(tt);

    return 0;
}

