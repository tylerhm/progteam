#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

#define MOD 1000000007

vector<vector<ll>> dp;
int n, k, d;

ll solve(int sum, int takenD) {
    if (sum == n)
        if (takenD)
            return 1;
    
    if (dp[sum][takenD] != -1)
        return dp[sum][takenD];

    ll possible = 0;
    int maxAddable = (n - sum <= k)? (n - sum) : k;
    for (int i = 1; i <= maxAddable; i++)
        possible = (possible % MOD + solve(sum + i, (i>=d || takenD)? 1: 0) % MOD) % MOD;

    return dp[sum][takenD] = possible;
}

int main() {
    cin >> n >> k >> d;
    // each tree contains itself in every subtree our dp can use this state
    // [sum size][taken needed edge?]
    dp = vector<vector<ll>>(n+10, vector<ll>(2, -1));
    cout << solve(0, 0) << "\n";
    return 0;
}
