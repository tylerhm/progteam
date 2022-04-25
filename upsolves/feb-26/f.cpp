#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int N; cin >> N;
    vector<vi> adj(N);

    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto dfs = [&](int v, int par, auto &&dfs) -> int {
        int maxDepth = 1;
        for (int u : adj[v]) if (u != par)
            maxDepth = max(maxDepth, dfs(u, v, dfs) + 1);
        return maxDepth;
    };

    auto isCentroid = [&](int v) {
        for (int u : adj[v]) if (dfs(u, v, dfs) > N/2)
            return false;
        return true;
    };

    int centroid = -1;
    for (int i = 0; i < N; i++)
        if (isCentroid(i)) {
            if (centroid != -1) {
                cout << -1 << endl;
                return 0;
            } else centroid = i;
        }

    auto getComponent = [&](int v, int par, vi &list, auto &&getComponent) -> void {
        list.push_back(v);
        for (int u : adj[v]) if (u != par)
            getComponent(u, v, list, getComponent);
    };

    vector<vi> forest(sz(adj[centroid]));
    for (int i = 0; i < sz(adj[centroid]); i++)
        getComponent(adj[centroid][i], centroid, forest[i], getComponent);

    // Remove the centroid from the graph
    for (int i = 0; i < N; i++) {
        if (i == centroid) adj[i].clear();
        for (int j = 0; j < sz(adj[i]); j++) if (adj[i][j] == centroid) {
            adj[i].erase(begin(adj[i]) + j);
            break;
        }
    }

    // Find centroids of children
    vector<vi> centroids(sz(forest));
    for (int i = 0; i < sz(forest); i++) {
        for (int j = 0; j < sz(forest[i]); j++) if (isCentroid(forest[i][j]))
            centroids[i].push_back(forest[i][j]);
    }

    map<vi, int> dp;
    for (int i = 0; i < sz(forest); i++) {

    }

    return 0;
}

