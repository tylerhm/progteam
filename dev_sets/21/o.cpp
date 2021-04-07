#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

struct prize {
    int day;
    int value;
    int wait;

    bool operator<(const prize& a) const
    {
        return day < a.day;
    }
};

// take it or leave it dp
vector<ll> dp;

ll solve(vector<prize>& prizes, int k)
{
    if (k == prizes.size())
        return 0;

    // if we have a valid dp state
    if (dp[k] != -1)
        return dp[k];

    // take it
    ll take = prizes[k].value;
    for (int i = k + 1; i < prizes.size(); i++)
    {
        if (prizes[i].day >= prizes[k].day + prizes[k].wait)
        {
            take += solve(prizes, i);
            break;
        }
    }

    // leave it
    ll leave = solve(prizes, k + 1);

    dp[k] = max(take, leave);
    return dp[k];
}

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        int k; cin >> k;
        vector<prize> prizes = vector<prize>();
        dp = vector<ll>(k, -1);
        for (int i = 0; i < k; i++)
        {
            int d, v, w; cin >> d >> v >> w;
            prizes.emplace_back(prize {d, v, w});
        }
        sort(prizes);
        cout << solve(prizes, 0) << "\n";
    }

    return 0;
}