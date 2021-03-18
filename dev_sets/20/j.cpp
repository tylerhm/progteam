#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int c, m; cin >> c >> m;
    vector<vector<ll>> sales(m, vector<ll>(c+1));
    rep(i, 0, m)
        rep(j, 1, c+1)
            cin >> sales[i][j];

    vector<ll> dp = vector<ll>(c+1);

    rep(i, 0, m) {
        vector<ll> currentBest = vector<ll>(c+1);
        for (int j = 0; j <= c; j++) {
            for (int k = 0; j - k >= 0; k++)
                currentBest[j] = max(currentBest[j], sales[i][k] + dp[j-k]);
        }
        dp = currentBest;
    }

    ll best = 0;
    for (auto v : dp) best = max(best, v);
    cout << best << "\n";

    return 0;    
}
