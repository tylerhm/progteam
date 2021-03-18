#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll minDist(vector<pair<int, int>> &dist, vector<bool> &seen) {
    ll minDis = INT_MAX, minIndex = -1;

    for (int v = 0; v < sz(seen); v++)
        if (!seen[v] && dist[v].first <= minDis)
            minDis = dist[v].first, minIndex = v;
    
    return minIndex;
}

string fancyDijkstras(vector<vector<int>> &adjList,
    vector<int> &times,
    set<pair<pair<int, int>, int>> &badPaths,
    int source)
{
    vector<pair<int, int>> dist(sz(adjList), {INT_MAX, -1});
    dist[source] = {0, -1};

    vector<bool> seen(sz(adjList), false);
    vector<bool> spSet(sz(adjList), false);
    seen[source] = true;

    for (int count = 0; count < sz(adjList) - 1; count++) {
        int u = minDist(dist, spSet);

        spSet[u] = true;

        for (int v : adjList[u]) {
            if (!spSet[v] &&
            dist[u].first != INT_MAX &&
            dist[u].first + times[v] < dist[v].first &&
            !badPaths.count({{dist[u].second, u}, v})) {
                dist[v] = {dist[u].first + times[v], u};
                seen[v] = true;
            }
        }
    }

    if (seen[sz(seen)-1]) return to_string(dist[sz(dist)-1].first + times[sz(dist)-1]);
    return "impossible";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vector<vector<int>> adjList(n);
    vector<int> times(n);
    set<pair<pair<int, int>, int>> badPaths;
    for (int i = 0; i < n; i++) {
        int m, t; cin >> m >> t;
        times[i] = t;
        
        adjList[i] = vector<int>(m);
        for (int j = 0; j < m; j++) {
            int s, v; cin >> s >> v; v--;
            for (int k = 0; k < s; k++) {
                int u; cin >> u; u--;
                badPaths.insert({{u, i}, v});
            }
            adjList[i][j] = v;
        }
    }

    cout << fancyDijkstras(adjList, times, badPaths, 0) << "\n";

    return 0;    
}