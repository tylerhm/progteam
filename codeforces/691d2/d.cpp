#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

struct glass {
    int cap, cur;
    bool operator<(glass a) { return cur < a.cur; }
};

// finite capacities
// ans = min(Ct, (s + t) / 2);

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    int maxi = 105;
    int total = 0;
    vector<glass> glasses(maxi);
    for (int i = 1; i <= n; i++) {
        int c, r; cin >> c >> r;
        glasses[i].cap = c;
        glasses[i].cur = r;
        total += r;
    }

    vector<vector<vector<int>>> dp(maxi, vector<vector<int>>(maxi, vector<int>(maxi*maxi)));
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int k = 0; k < maxi; k++)
                dp[i][j][k] = -oo;
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < maxi*maxi; k++)
                if (dp[i][j][k] != -oo) {
                    dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
                    dp[i + 1][j + 1][k + glasses[i + 1].cap] = max( dp[i + 1][j + 1][k + glasses[i + 1].cap],
                                                                    dp[i][j][k] + glasses[i + 1].cur);
                }
    for (int i = 1; i <= n; i++) {
        double ans = 0;
        for (int j = 0; j < maxi*maxi; j++) {
            double cap = j;
            ans = max(ans, min(cap, total / 2.0 + dp[n][i][j] / 2.0));
        }
        cout << fixed << setprecision(9) << ans << " ";
    }

    return 0;
}
