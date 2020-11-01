#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

string s1, s2;
vector<vector<ll>> dp;

ll solve(int s1k, int s2k)
{
    if ((s1k < 0 && s2k < 0) || s2k < 0)
        return 1;

    if (s1k < 0)
        return 0;

    if (dp[s1k][s2k] != -1)
        return dp[s1k][s2k];

    if (s1[s1k] == s2[s2k])
        return dp[s1k][s2k] = solve(s1k - 1, s2k - 1) + solve(s1k - 1, s2k);
    else
        return dp[s1k][s2k] = solve(s1k - 1, s2k);
}

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        cin >> s1 >> s2;
        dp = vector<vector<ll>>(s1.size() + 10, vector<ll>(s2.size() + 10, -1));
        cout << solve(s1.size()-1, s2.size()-1) << "\n";
    }

    return 0;
}
