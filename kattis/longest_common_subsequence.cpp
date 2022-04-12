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

    int n, l; cin >> n >> l;
    vector<vector<bool>> adj(l, vector<bool>(l, true));
    rep(i,0,l) adj[i][i] = false;
    rep(i, 0, n) {
        string str; cin >> str;
        for (int i = 0; i < l; i++)
            for (int j = 0; j < i; j++)
                adj[str[i] - 'A'][str[j] - 'A'] = false;
    }

    int ans = 0;
    for (int i = 0; i < l; i++) {
        queue<pii> bfs;
        bfs.emplace(i, 1);

        while (!bfs.empty()) {
            auto [cur, dist] = bfs.front();
            bfs.pop();
            ans = max(ans, dist);
            for (int j = 0; j < l; j++)
                if (adj[cur][j])
                    bfs.emplace(j, dist + 1);
        }
    }

    cout << ans << "\n";

    return 0;
}

