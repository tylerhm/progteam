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

void solve() {
    int c, d, v; cin >> c >> d >> v;

    vector<pii> dogLovers, catLovers;
    for (int i = 0; i < v; i++) {
        string one, two; cin >> one >> two;
        char loveType = one.substr(0, 1)[0];
        char hateType = two.substr(0, 1)[0];
        int love = stoi(one.substr(1)) - 1;
        int hate = stoi(two.substr(1)) - 1;

        if (loveType == 'D') dogLovers.emplace_back(love, hate);
        else catLovers.emplace_back(love, hate);
    }

    Dinic flow(sz(dogLovers) + sz(catLovers) + 2);
    int s = sz(dogLovers) + sz(catLovers), t = s+1;

    for (int i = 0; i < sz(dogLovers); i++)
        flow.addEdge(s, i, 1);
    for (int i = 0; i < sz(catLovers); i++)
        flow.addEdge(sz(dogLovers) + i, t, 1);

    for (int i = 0; i < sz(dogLovers); i++) {
        for (int j = 0; j < sz(catLovers); j++) {
            int dogLove = dogLovers[i].first;
            int dogHate = catLovers[j].second;
            int catLove = catLovers[j].first;
            int catHate = dogLovers[i].second;
            if (dogLove == dogHate || catLove == catHate)
                flow.addEdge(i, sz(dogLovers) + j, 1);
        }
    }

    cout << v-flow.calc(s, t) << nl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
        solve();

    return 0;
}
