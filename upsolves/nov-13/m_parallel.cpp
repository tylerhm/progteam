#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UF {
    vi e;
    UF(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int m, n, q; cin >> m >> n >> q;
    vector<vi> height(m, vi(n));
    for (auto &v : height) for (auto &x : v) cin >> x;

    int maxWeight = 0;
    for (auto &v : height) maxWeight = max(maxWeight, *max_element(all(v)));

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

    int ans[q];
    int lo = 0, hi = maxWeight, mid = (lo + hi) >> 1;
    typedef tuple<int, int, int, int, int, int> ti6;
    // mid, lo, hi, qs, qe, idx
    priority_queue<ti6, vector<ti6>, greater<ti6>> queries;
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        if (x1 == x2 && y1 == y2) ans[i] = height[x1][y1];
        else queries.emplace(mid, lo, hi, idx(x1, y1), idx(x2, y2), i);
    }

    while (sz(queries)) {
        priority_queue<ti6, vector<ti6>, greater<ti6>> newQueries;

        UF dsu(m*n);
        int edgeIdx = 0;
        while (sz(queries)) {
            auto [mid, lo, hi, qs, qe, idx] = queries.top();
            queries.pop();
            // union all edges up to this mid value
            while (edgeIdx < sz(edges) && get<0>(edges[edgeIdx]) <= mid)
                dsu.join(get<1>(edges[edgeIdx]), get<2>(edges[edgeIdx])), edgeIdx++;

            if (dsu.sameSet(qs, qe)) hi = mid;
            else lo = mid + 1;
            mid = (lo + hi) >> 1;

            if (lo >= hi) ans[idx] = hi;
            else newQueries.emplace(mid, lo, hi, qs, qe, idx);
        }

        queries = newQueries;
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << nl;

    return 0;
}

