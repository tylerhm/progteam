#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

double pairDist(pair<int, int>& p1, pair<int, int>& p2) {
    return sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}

struct edge {
    int src;
    int dest;
    double weight;
    edge(int s, int d, double w) : src(s), dest(d), weight(w) {}

    bool operator<(const edge& a) const
    {
        return weight < a.weight;
    }
};

struct DSU {
    vector<int> s;
    DSU(int n) : s(n, -1) {}
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

int main()
{
    int n; cin >> n;
    while (n != 0)
    {
        vector<edge> edges = vector<edge>();
        vector<pair<int, int>> locs = vector<pair<int, int>>(n);
        for (int i = 0; i < n; i++)
        {
            int x, y; cin >> x >> y;
            locs[i] = make_pair(x, y);
            for (int j = 0; j <= i; j++)
            {
                double dist = pairDist(locs[i], locs[j]);
                edges.emplace_back(i, j, dist);
            }
        }

        sort(edges);
        DSU dsu = DSU(n);
        double cost = 0;

        int edge = 0;
        int i = 0;
        while (edge < n - 1)
        {
            auto e = edges[i++];

            if (!dsu.same(e.src, e.dest)) {
                dsu.join(e.src, e.dest);
                cost += e.weight;
                edge++;
            }
        }
        
        printf("%.2lf\n", cost);
        cin >> n;
    }
    return 0;
}
