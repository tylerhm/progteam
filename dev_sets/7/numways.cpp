#include <bits/stdc++.h>
#define ll long long int
int mod = (int)(7 + 1e9);
int oo = -1^1<<31;
using namespace std;

vector<vector<int>> dp;
vector<int> denoms;
int k, nDenom;

int solve(int sum, int curDenom)
{
    if (sum > k) return 0;
    if (sum == k) return 1;

    if (dp[sum][curDenom] != -1)
        return dp[sum][curDenom];

    int numWays = 0;
    for (int i = curDenom; i < nDenom; i++)
        numWays = (numWays + solve(sum + denoms[i], i)) % mod;

    return dp[sum][curDenom] = numWays;

}
int main()
{
    int n; cin >> n;
    while (n--)
    {
        cin >> k >> nDenom;
        denoms = vector<int>(nDenom);
        dp = vector<vector<int>>(k+10, vector<int>(nDenom + 10, -1));
        for (int i = 0; i < nDenom; i++) cin >> denoms[i];
        cout << solve(0, 0) << "\n";
    }
    return 0;
}