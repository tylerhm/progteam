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

int main()
{
    int size = 4;
    FordFulkerson g(size);
    g.conSource(0, 16);
    g.conSource(2, 13);
    g.add(0, 1, 12);
    g.add(0, 2, 10);
    g.add(1, 2, 9);
    g.add(2, 0, 4);
    g.add(2, 3, 14);
    g.add(3, 1, 7);
    g.conSink(1, 20);
    g.conSink(3, 4);

    cout << g.ff() << endl;

    return 0;
}