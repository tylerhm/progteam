#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

ll mn;

bool backtracker(vector<pair<vector<int>, ll>> &adjList, vector<bool> &visited, int u, bool used) {
    mn = min(mn, adjList[u].second);
    if (u == 0) return true;

    for (int v : adjList[u].first) {
        if (visited[v]) continue;

        if (adjList[u].second < adjList[v].second) {
            visited[v] = true;
            if (backtracker(adjList, visited, v, used));
                return true;
            visited[v] = false;
        }
        else {
            if (!used) {
                visited[v] = true;
                if (backtracker(adjList, visited, v, true));
                    return true;
                visited[v] = false;
            }
        }
    }

    return false;
}

void solve(int t) {
    int n, m; cin >> n >> m;
    vector<pair<vector<int>, ll>> adjList(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adjList[u].first.push_back(v);
    }
    queue<int> bfs;
    vector<bool> visited(n, false);
    bfs.push(0);
    visited[0] = true;
    adjList[0].second = 0;
    while (!bfs.empty()) {
        int u = bfs.front();
        bfs.pop();

        for (int v : adjList[u].first) {
            if (visited[v]) continue;
            visited[v] = true;
            adjList[v].second = adjList[u].second + 1;
            bfs.push(v);
        }
    }

    /*
    for (int i = 0; i < n; i++) {
        cout << adjList[i].second << " ";
    }
    cout << nl;
    */
    for (int i = 0; i < n; i++) {
        mn = INT_MAX;
        vector<bool> visited(n, false);
        backtracker(adjList, visited, i, false);
        cout << mn << " ";
    }
    cout << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tt; cin >> tt;
    for (int t = 1; t <= tt; t++)
        solve(t);

    return 0;
}
