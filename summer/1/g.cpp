#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll mx = INT_MIN;
vector<vector<pair<int, int>>> proficientPositions;
vector<bool> visited;

void go(int idx, ll sum) {
    if (idx == 11) {
        for (bool b : visited) if (!b) return;
        mx = max(mx, sum);
        return;
    }

    for (auto p : proficientPositions[idx]) {
        if (visited[p.first]) continue;
        visited[p.first] = true;
        go(idx + 1, sum + p.second);
        visited[p.first] = false;
    }
}

void solve(int tt) {
    proficientPositions = vector<vector<pair<int, int>>>(11);
    mx = INT_MIN;
    rep(i, 0, 11) {
        rep(j, 0, 11) {
            int p; cin >> p;
            if (p > 0) proficientPositions[i].push_back({j, p});
        }
    }

    visited = vector<bool>(11, false);
    go(0, 0);
    cout << mx << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    rep(tt, 0, t)
        solve(tt);

    return 0;    
}
