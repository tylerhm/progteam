#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct DSU {
    vi par, compDeg2, deg;
    int numDeg0, numDeg2, numCompDeg2;
    DSU(int n) : par(n, -1), compDeg2(n, 0), deg(n, 0), numDeg0(n), numDeg2(0), numCompDeg2(0) {}
    void incDegree(int a) {
        if (++deg[a] == 1) numDeg0--;
        if (deg[a] == 2) {
            numDeg2++;
            if (++compDeg2[find(a)] == -par[find(a)])
                numCompDeg2++;
        }
        if (deg[a] == 3) {
            numDeg2--;
            if (compDeg2[find(a)]-- == -par[find(a)])
                numCompDeg2--;
        }
    }
    void updateDegree(int a, int b) { incDegree(a); incDegree(b); }
    int find(int a) { return par[a] < 0 ? a : par[a] = find(par[a]); }
    bool join(int a, int b) {
        updateDegree(a, b);
        if ((a = find(a)) == (b = find(b)))
          return false;

        if (par[b] < par[a]) swap(a, b);
        numCompDeg2 -= (compDeg2[a] == -par[a]);
        numCompDeg2 -= (compDeg2[b] == -par[b]);

        par[a] += par[b];
        par[b] = a;
        compDeg2[a] += compDeg2[b];
        compDeg2[b] = 0;

        numCompDeg2 += (compDeg2[a] == -par[a]);

        return true;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        a--; b--;
        edges.emplace_back(w, a, b);
    }
    sort(all(edges), greater<tuple<int, int, int>>());

    int q; cin >> q;
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].first;
        queries[i].second = i;
    }
    sort(all(queries), greater<pair<int, int>>());

    DSU dsu(n);
    int edgeIdx = 0;
    vector<pii> ans(q);
    for (auto &[q, idx] : queries) {
        while (get<0>(edges[edgeIdx]) >= q) {
            int a = get<1>(edges[edgeIdx]), b = get<2>(edges[edgeIdx++]);
            dsu.join(a, b);
        }

        int afterNodes = n - dsu.numDeg0 - dsu.numDeg2 + dsu.numCompDeg2;
        int afterEdges = edgeIdx - dsu.numDeg2 + dsu.numCompDeg2;
        ans[idx] = {afterNodes, afterEdges};
    }

    for (auto &[x, y] : ans)
        cout << x << ' ' << y << nl;

    return 0;
}

