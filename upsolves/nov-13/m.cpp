#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct dsu {
    vi ans, par;
    vector<set<int>> queries;
    dsu(int n, int q) : ans(q), par(n, -1), queries(n) {}
    int find(int i) { return par[i] < 0 ? i : par[i] = find(par[i]); }
    bool join(int a, int b, int w) {
        if ((a = find(a)) == (b = find(b))) return false;
        if (par[b] < par[a]) swap(a, b);
        par[a] += par[b];
        par[b] = a;

        for (int i : queries[b]) {
            if (queries[a].count(i))
                ans[i] = w;
            queries[a].insert(i);
        }
        queries[b].clear();

        return true;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int m, n, q; cin >> m >> n >> q;
    vector<vi> height(m, vi(n));
    for (auto &v : height) for (auto &x : v) cin >> x;

    // w, a, b
    vector<tuple<int, int, int>> edges;
    auto idx = [&](int row, int col) { return row * n + col; };
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i) edges.emplace_back(max(height[i-1][j], height[i][j]), idx(i, j), idx(i-1, j));
            if (j) edges.emplace_back(max(height[i][j-1], height[i][j]), idx(i, j), idx(i, j-1));
        }
    }
    sort(all(edges));

    dsu d(m*n, q);
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        if (x1 == x2 && y1 == y2) d.ans[i] = height[x1][y1];
        else {
            d.queries[idx(x1, y1)].insert(i);
            d.queries[idx(x2, y2)].insert(i);
        }
    }

    for (auto &[w, a, b] : edges) d.join(a, b, w);
    for (int i : d.ans) cout << i << nl;

    return 0;
}

