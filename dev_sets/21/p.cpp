#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct DSU {
    vector<int> s;
    DSU(int n): s(n, -1) {}
    int find(int i) { return s[i] < 0 ? i : s[i] = find(s[i]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (s[a] > s[b]) swap(a, b);
        s[a] += s[b], s[b] = a;
        return true;
    }
    int size(int i) { return -s[find(i)]; }
    bool same(int a, int b) { return find(a) == find(b); }
};

struct edge {
    int u, v;
    ll w;

    edge(int u, int v, ll w) : u(u), v(v), w(w) {}

    bool operator<(edge o) {
        return w < o.w;
    }
};

ll dist(pair<int, int> a, pair<int, int> b, int ac, int bc) {
    ll dx = abs(a.first - b.first);
    ll dy = abs(a.second - b.second);
    return dx*ac + dy*bc;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, a, b; cin >> n >> a >> b;
    vector<pair<int, int>> points(n);
    rep (i, 0, n) {
        string room; cin >> room;
        int y, x;
        if (room.length() == 3) {
            y = room[0] - '0';
            x = stoi(room.substr(1));
        }
        else {
            y = stoi(room.substr(0, 2));
            x = stoi(room.substr(2));
        }
        points[i] = make_pair(x, y);
    }

    DSU dsu = DSU(n);
    vector<edge> edges;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            edges.emplace_back(i, j, dist(points[i], points[j], a, b));

    sort(all(edges));

    ll final_cost = 0;
    int e = 0;
    int i = 0;
    while (e < n - 1 && i < edges.size()) {
        edge next = edges[i++];

        if (!dsu.same(next.u, next.v)) {
            dsu.join(next.u, next.v);
            final_cost += next.w;
        }
    }

    cout << final_cost << "\n";

    return 0;    
}
