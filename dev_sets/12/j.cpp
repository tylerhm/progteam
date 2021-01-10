#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

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
    int src, dest;
    double weight;
    edge(int s, int d, double w) : src(s), dest(d), weight(w) {}
    bool operator<(edge a) {
        return weight < a.weight;
    }
};

double dist(pair<int, int> p1, pair<int, int> p2) {
    return sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));
}

void solve(int n) {
    vector<pair<int, int>> points(n);
    vector<edge> edges;
    DSU dsu(n);

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        points[i] = {x, y};
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double d = dist(points[i], points[j]);
            edges.emplace_back(i, j, d);
            edges.emplace_back(j, i, d);
        }
    }

    sort(all(edges));
    int taken = 0;
    double length = 0;
    for (int i = 0; i < edges.size() && taken < (n-1); i++) {
        if (!dsu.same(edges[i].src, edges[i].dest)) {
            dsu.join(edges[i].src, edges[i].dest);
            taken++;
            length += edges[i].weight;
        }
    }
    cout << fixed << setprecision(2) << length << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    while (n != 0) {
        solve(n);
        cin >> n;
    }

    return 0;
}
