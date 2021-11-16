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
    int h, w; cin >> h >> w;
    h += 2; w += 2;
    vector<string> board(h);
    string dot = ""; for (int i = 0; i < w; i++) dot += ".";
    board[0] = dot;
    board[h-1] = dot;
    for (int i = 1; i < h - 1; i++) cin >> board[i], board[i] = "." + board[i] + ".";

    auto getIdx = [&](int row, int col) {
        return row * w + col;
    };

    Dinic flow(w*h + 2);
    int s = w*h, t = s + 1;

    for (int col = 0; col < w; col++) {
        flow.addEdge(s, getIdx(0, col), 1);
        flow.addEdge(s, getIdx(h-1, col), 1);
    }

    for (int row = 1; row < h - 1; row++) {
        flow.addEdge(s, getIdx(row, 0), 1);
        flow.addEdge(s, getIdx(row, w-1), 1);
    }

    int DR[] = {1, 0, -1, 0}, DC[] = {0, 1, 0, -1};
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            if (board[row][col] != '.') continue;
            int idx = getIdx(row, col);
            for (int d = 0; d < 4; d++) {
                int nr = row + DR[d];
                int nc = col + DC[d];
                if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
                    if (board[nr][nc] == '.')
                        flow.addEdge(idx, getIdx(nr, nc), 1);
                    else if (board[nr][nc] == 'D')
                        flow.addEdge(idx, t, 1);
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

