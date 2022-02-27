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


    return 0;
}

