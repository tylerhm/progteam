#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct edge {
    ll u, v, w;
    edge(ll u=0, ll v=0, ll w=0) : u(u), v(v), w(w) {}
    bool operator<(edge a) { return w < a.w; }
};

bool EdgeComparator(edge a, edge b) {
    return a.w > b.w;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m, l; cin >> n >> m >> l;
    ll alreadyBuiltLength = 0;
    vector<vector<edge>> graph(n);
    rep(i, 0, m) {
        ll u, v, w; cin >> u >> v >> w;
        u--; v--;
        graph[u].emplace_back(u, v, w);
        graph[v].emplace_back(v, u, w);
        if (i < l) alreadyBuiltLength += w;
    }

    ll mstCost = 0;

    priority_queue<edge, vector<edge>, function<bool(edge, edge)>> edges(EdgeComparator);
    for (auto e : graph[0])
        edges.push(e);

    vector<bool> visited(n, false);
    visited[0] = true;

    ll numFound = 0;

    while (!edges.empty() && numFound < n-1) {
        edge e = edges.top(); edges.pop();
        if (visited[e.u] && visited[e.v]) continue;

        mstCost += e.w;
        numFound++;

        if (!visited[e.v]) {
            visited[e.v] = true;
            for (auto ne : graph[e.v])
                edges.push(ne);
        }
        else {
            visited[e.u] = true;
            for (auto ne : graph[e.u])
                edges.push(ne);
        }
    }

    cout << ((numFound >= n-1 && mstCost <= alreadyBuiltLength)? "possible" : "impossible") << "\n";


    return 0;    
}
