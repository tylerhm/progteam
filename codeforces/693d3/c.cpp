#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n; cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; i++) cin >> vals[i];
    int mx = 0;
    vector<int> dp(n, -1);
    for (int i = n-1; i >= 0; i--) {
        int v = i, score = 0;
        while (v < n) {
            if (dp[v] != -1) {
                score += dp[v];
                break;
            }
            score+=vals[v];
            v+=vals[v];
        }
        dp[i] = score;
        mx = max(mx, score);
    }
    cout << mx << nl;
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
