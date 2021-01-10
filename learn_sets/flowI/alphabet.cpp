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
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n_cases; cin >> n_cases;
    for (int iter = 1; iter <= n_cases; iter++)
    {
        // graph with enough nodes for a-z of each color
        FordFulkerson g(26*2);

        // get frequency of each letter in greens and reds
        vector<int> reds(26, 0), greens(26, 0);
        string letters; cin >> letters;
        for (char c : letters)
            greens[c - 'a']++;
        cin >> letters;
        for (char c : letters)
            reds[c - 'a']++;
        
        // connect sources and sinks
        for (int i = 0; i < 26; i++)
        {
            g.conSource(i, greens[i]);
            g.conSink(i+26, reds[i]);
        }

        // connect middle
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                if (abs(j - i) >= 3)
                    g.add(i, j + 26, 50);

        cout << g.ff() << endl;
    }

    

    return 0;
}
