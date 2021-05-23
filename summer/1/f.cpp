#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, t, landing, takeoff;
map<int, int> tunnels;
vector<vector<int>> paths;
vector<bool> visited;

bool go(int loc, int tunnelsTaken) {
    if (tunnels[loc]) {
        tunnelsTaken++;
        int newLoc = tunnels[loc];
        if (newLoc == takeoff) return tunnelsTaken == t;
        if (visited[newLoc]) return false;
        visited[newLoc] = true;
        return go(newLoc, tunnelsTaken);
    }
    
    for (int path : paths[loc]) {
        if (path == takeoff) return tunnelsTaken == t;
        if (visited[path]) return false;
        visited[path] = true;
        if (go(path, tunnelsTaken)) return true;
        visited[path] = false;
    }
    return false;
}

bool solve(int tt) {
    cin >> n >> m >> t;
    cin >> landing >> takeoff;

    tunnels.clear();
    paths = vector<vector<int>>(n, vector<int>());

    int a, b;
    rep(i, 0, m) {
        cin >> a >> b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }

    rep(i, 0, t) {
        cin >> a >> b;
        if (tunnels[a]) return false;
        tunnels[a] = b;
    }

    visited = vector<bool>(n, false);
    return go(landing, 0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    rep(tt, 0, t)
        cout << (solve(tt) ? "POSSIBLE" : "IMPOSSIBLE") << endl;

    return 0;    
}
