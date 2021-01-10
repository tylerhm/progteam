#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m; cin >> n >> m;
    while (n != 0 && m != 0) {
        /*
        if (n == 1 || m == 1) {
            cout << 1 << nl;
            cin >> n >> m;
            continue;
        }
        */
        vector<vector<int>> grid(n, vector<int>(m));
        vector<vector<int>> dp(n+10, vector<int>(m+10, 0));
        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if (i == 0 || j == 0)
                    mx = max(mx, dp[i][j] = grid[i][j]);
            }
        }

        
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (grid[i][j] == 1)
                    mx = max(mx, dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1);
                else
                    dp[i][j] = 0;

        /*
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << dp[i][j] << ' ';
            cout << nl;
        }
        */

        cout << mx << nl;
        cin >> n >> m;
    }

    return 0;
}
