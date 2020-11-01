#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int n;
vector<ll> dp = vector<ll>(100010, -1);
vector<ll> freq = vector<ll>(100010, 0);

ll solve(int k) {
    if (dp[k] != -1)
        return dp[k];

    ll take = solve(k - 2) + freq[k] * k;
    ll leave = solve(k - 1);

    return dp[k] = max(take, leave);
}

int main()
{
    cin >> n;
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        freq[val]++;
    }
    dp[0] = 0;
    dp[1] = freq[1];
    cout << solve(100000) << "\n";
    return 0;
}
