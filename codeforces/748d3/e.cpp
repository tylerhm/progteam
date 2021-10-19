#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> inDeg(n, 0);
    vector<vi> adjList(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        inDeg[u]++;
        inDeg[v]++;
    }

    queue<pii> bfs;
    vector<int> dists(n, 0);
    for (int i = 0; i < n; i++)
        if (inDeg[i] == 1) bfs.emplace(i, 0);

    while (!bfs.empty()) {
        auto [node, dist] = bfs.front();
        dists[node] = dist;
        bfs.pop();

        for (auto i : adjList[node]) {
            if (--inDeg[i] == 1) {
                bfs.emplace(i, dist + 1);
            }
        }
    }

    int left = 0;
    for (int i = 0; i < n; i++) {
        if (dists[i] == k) left++;
    }

    cout << left << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
