#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

namespace SCCTarjan {
    vector<int> val, comp, z, cont;
    int Time, ncomps;
    template <class G, class F>
    int dfs(int j, G& g, F& f) {
        int low = val[j] = ++Time, x;
        z.push_back(j);
        for (auto e : g[j])
            if (comp[e] < 0) low = min(low, val[e] ?: dfs(e, g, f));
        if (low == val[j]) {
            do {
                x = z.back();
                z.pop_back();
                comp[x] = ncomps;
                cont.push_back(x);
            } while (x != j);
            f(cont);
            cont.clear();
            ncomps++;
        }
        return val[j] = low;
    }
    template <class G, class F>
    vector<int> scc(G& g, F f) {
        int n = g.size();
        val.assign(n, 0);
        comp.assign(n, -1);
        Time = ncomps = 0;
        for (int i = 0; i < n; i++)
            if (comp[i] < 0) dfs(i, g, f);
        return comp;
    }
    template <class G> // convenience function w/o lambda
    vector<int> scc(G& g) {
        return scc(g, [](auto& v) {});
    }
} // namespace SCCTarjan

void solve(int tt) {
    int n, m; cin >> n >> m;

    vector<vector<int>> adjList(n);

    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        adjList[a].push_back(b);
    }

    auto scc = SCCTarjan::scc(adjList);

    set<int> seen;

    rep(i, 0, n) {
        if (seen.count(scc[i])) continue;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    rep(tt, 0, t) solve(tt);

    return 0;    
}
