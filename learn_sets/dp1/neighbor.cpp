#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

vector<ll> dp;
vector<int> houses;

ll solve(int k)
{
    if (k >= houses.size())
        return 0;

    if (dp[k] != -1)
        return dp[k];

    // take
    ll take = houses[k] + solve(k+2);
    // leave
    ll leave = solve(k+1);

    return dp[k] = max(take, leave);
}

int main()
{
    int n_cases; cin >> n_cases;
    for (int c = 0; c < n_cases; c++)
    {
        int k; cin >> k;
        houses = vector<int>(k);
        dp = vector<ll>(k + 10, -1);
        for (int i = 0; i < k; i++) cin >> houses[i];
        cout << "Case #" << c+1 << ": " << solve(0) << " :";
        for (int i = 0; i < k; i++)
        {
            ll take = houses[i] + solve(i+2);
            ll leave = solve(i+1);
            if (take >= leave)
                cout << " " << i++;
        }
        cout << "\n";
    }

    return 0;
}
