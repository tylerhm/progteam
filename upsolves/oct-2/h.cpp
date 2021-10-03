#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD (int)1e9+7

int n, m, k;
vi a, b;
vector<vector<vector<ll>>> dp; // [aloc][bloc][kLeft]

int solve(int aloc, int bloc, int kLeft) {
    if (kLeft == 0) return 1;
    if (aloc == n || bloc == m) return 0;

    auto &ans = dp[aloc][bloc][kLeft];
    if (ans != -1) return ans;
    ans = 0;

    if (a[aloc] > b[bloc])
        ans = (ans + solve(aloc + 1, bloc + 1, kLeft - 1)) % MOD;
    ans = (ans + solve(aloc + 1, bloc, kLeft)) % MOD;
    ans = (ans + solve(aloc, bloc + 1, kLeft)) % MOD;
    ans = ((ans - solve(aloc + 1, bloc + 1, kLeft)) % MOD + MOD) % MOD;
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> n >> m >> k;
    a = vi(n); b = vi(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    sort(all(a));
    sort(all(b));
    // reverse(all(a));
    // reverse(all(b));

    dp = vector<vector<vector<ll>>>(
        n, vector<vector<ll>>(
        m, vector<ll>(
        k + 1, -1
    )));
    
    cout << solve(0, 0, k) << endl;

    return 0;
}
