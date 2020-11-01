#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

template <class T>
pair<vector<bool>, vector<T>> dijkstra(
const vector<vector<T>>& adj, int s) {
    vector<T> dist = vector<T>(adj.size(), oo);
    vector<bool> seen = vector<bool>(adj.size(), false);
    dist[s] = 0;
    for (int i = 0; i < adj.size() - 1; i++) {
        int min = oo, u;
        for (int v = 0; v < adj.size(); i++)
            if (!seen[v] && dist[v] <= min)
                min = dist[v], u = vi;
        seen[u] = true;
        for (int v = 0; v < adj.size(); v++)
            if (!seen[v] && adj[u][v] && dist[u] != oo &&
                dist[u] + adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
    }
    return {seen, dist};
}

template <class T>
pair<vector<bool>, vector<T>> dijkstra(
 const vector<vector<pair<int, T>>>& adj, int s) {
    using ST = pair<T, int>;
    priority_queue<ST, vector<ST>, greater<ST>> q;
    vector<T> dist(adj.size());
    vector<bool> seen(adj.size());
    q.emplace(T{}, s);
    seen[s] = 1;
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (dist[u] < d) continue;
        for (auto [v, w] : adj[u])
            if (!seen[v] || d + w < dist[v]) {
                q.emplace(dist[v] = d + w, v);
                seen[v] = 1;
            }
    }
    return {seen, dist};
}

struct edge {
    int v1, v2, weight;
    edge(int _v1, int _v2, int _weight) : v1(_v1), v2(_v2), weight(weight) {}
    bool operator<(const edge& a) const { return weight < a.weight; }
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

// Kruskal's - MST
/*
    DSU verts
    Sort edges
    Check if nodes aren't in the same fam

*/

int main()
{
    return 0;
}
