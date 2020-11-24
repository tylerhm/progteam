#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

string s;

ll findOcc(string a, string b)
{
    int m = a.size();
    int n = b.size();

    vector<vector<ll>> dp = vector<vector<ll>>(m+10, vector<ll>(n+10));

    for (int i = 0; i <= n; i++) dp[0][i] = 0;
    for (int i = 0; i <= m; i++) dp[i][0] = 1;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[m][n];
}

int main()
{
    int n_cases; cin >> n_cases;
    for (int iter = 1; iter <= n_cases; iter++)
    {
        int n; cin >> n;
        cin >> s;
        cout << findOcc(s, "COW") << "\n"; 
    }

    return 0;
}