#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

struct FordFulkerson {
    int n, source, sink;
    vector<vector<int>> cap;
    FordFulkerson(int size) : n(size + 2), source(n - 2), sink(n - 1), cap(vector<vector<int>>(n, vector<int>(n, 0))) {}
    void add(int v, int u, int c) {
        cap[v][u] = c;
    }
    void conSource(int v, int c) {
        cap[source][v] = c;
    }
    void conSink(int v, int c) {
        cap[v][sink] = c;
    }
    int ff() {
        vector<bool> seen(n, false);
        int flow = 0;

        // find all aug paths
        while (true) {
            // run dfs
            fill(all(seen), false);
            int res = dfs(source, seen, oo);
            if (res == 0) break;
            flow += res;
        }
        return flow;
    }
    int dfs(int v, vector<bool> &seen, int minF) {
        if (v == sink) return minF;
        if (seen[v]) return 0;
        seen[v] = true;
        int flow = 0;
        for (int i = 0; i < n; i++) {
            if (cap[v][i] > 0)
                flow = dfs(i, seen, min(cap[v][i], minF));
            if (flow > 0) {
                cap[v][i] -= flow;
                cap[i][v] += flow;
                return flow;
            }
        }
        return 0;
    }
};

struct segment {
    pair<int, int> p1, p2;
    segment(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2) {}
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n_cases; cin >> n_cases;
    for (int iter = 1; iter <= n_cases; iter++)
    {
        int n; cin >> n;
        vector<segment> vertical, horizontal;
        for (int i = 0; i < n; i++)
        {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            // vert
            if (y2 - y1 == 0)
                horizontal.emplace_back(x1, (y1 < y2)? y1 : y2, x2, (y1 < y2)? y2 : y1);
            // hori
            else
                vertical.emplace_back((x1 < x2)? x1 : x2, y1, (x1 < x2)? x2 : x1, y2);
        }
        FordFulkerson g(n);
        // solve with bipartite matching
        // setup sources
        for (int i = 0; i < horizontal.size(); i++)
            g.conSource(i, 1);
        for (int i = 0; i < vertical.size(); i++)
            g.conSink(horizontal.size() + i, 1);

        for (int i = 0; i < horizontal.size(); i++)
            for (int j = 0; j < vertical.size(); j++)
                if (!(horizontal[i].p2.first < vertical[j].p1.first ||
                    horizontal[i].p1.first > vertical[j].p1.first ||
                    horizontal[i].p1.second > vertical[j].p2.second ||
                    horizontal[i].p1.second < vertical[j].p1.second))
                    g.add(i, horizontal.size() + j, 1);
        
        cout << n - g.ff() << "\n";
    }

    return 0;
}
