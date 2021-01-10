#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
#define MOD 1000000007
int oo = -1^1<<31;
using namespace std;

int k;
vector<int> prefixSums = vector<int>(100010);
vector<int> dp = vector<int>(100010, -1);

ll solve(int n) {
    if (n == 0) return 1;

    if (dp[n] != -1)
        return dp[n];

    ll white = 0, red;
    if (n >= k)
        white = solve(n - k) % MOD;
    red = solve(n - 1) % MOD;

    return dp[n] = (white + red) % MOD;
}

int main()
{
    int n_cases; cin >> n_cases >> k;

    prefixSums[0] = 0;
    for (int i = 1; i <= 100000; i++)
        prefixSums[i] = (prefixSums[i - 1] + solve(i)) % MOD;

    while (n_cases--)
    {
        int a, b; cin >> a >> b;
        cout << (prefixSums[b] - prefixSums[a-1] + MOD) % MOD << "\n";
    }
    return 0;
}
