#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

vector<vector<ll>> dp;
vector<int> gold;

ll solve(int l, int r)
{
    if (l > r)
        return 0;

    if (dp[l][r] != -1)
        return dp[l][r];

    // take left
    ll left = gold[l] - solve(l + 1, r);
    // take right
    ll right = gold[r] - solve(l, r - 1);

    return dp[l][r] = max(left, right);

}

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        int n; cin >> n;
        gold = vector<int>(n);
        dp = vector<vector<ll>>(n + 10, vector<ll>(n + 10, -1));
        for (int i = 0; i < n; i++) cin >> gold[i];
        cout << solve(0, n-1) << "\n";
    }
    return 0;
}
