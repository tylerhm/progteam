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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    const int DIM = 12;
    int n; cin >> n;
    vector<vector<vector<bool>>> cells(DIM, vector<vector<bool>>(DIM, vector<bool>(DIM, false)));
    for (int i = 0; i < n; i++) {
        int x, y, z; cin >> x >> y >> z;
        cells[x+1][y+1][z+1] = true;
    }

    auto idx = [&](int x, int y, int z) {
        return x * DIM * DIM + y * DIM + z;
    };

    Dinic flow(DIM*DIM*DIM+2);
    int s = DIM*DIM*DIM, t = s + 1;

    int DX[] = {1, -1, 0, 0, 0, 0},
        DY[] = {0, 0, 1, -1, 0, 0},
        DZ[] = {0, 0, 0, 0, 1, -1};
    for (int x = 0; x < DIM; x++)
        for (int y = 0; y < DIM; y++)
            for (int z = 0; z < DIM; z++) {
                int from = idx(x, y, z);
                if (!x || !y || !z || x == DIM - 1 || y == DIM - 1 || z == DIM - 1)
                    flow.addEdge(s, from, 1);
                if (cells[x][y][z]) continue;
                for (int d = 0; d < 6; d++) {
                    int nx = x + DX[d];
                    int ny = y + DY[d];
                    int nz = z + DZ[d];
                    if (nx < 0 || nx >= DIM ||
                        ny < 0 || ny >= DIM ||
                        nz < 0 || nz >= DIM) continue;
                    int to = idx(nx, ny, nz);
                    if (cells[nx][ny][nz]) flow.addEdge(from, t, 1);
                    else flow.addEdge(from, to, 1);
                }
            }

    cout << flow.calc(s, t) << nl;

    return 0;
}

