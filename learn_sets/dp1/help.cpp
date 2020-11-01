#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

vector<pair<int,int>> questions;
vector<vector<ll>> dp;
int mins;

ll solve(int k, int curMin)
{
    if (k == questions.size() || (curMin + questions[k].first > mins) || curMin >= mins)
        return 0;

    if (dp[k][curMin] != -1)
        return dp[k][curMin];

    ll take = questions[k].second + solve(k+1, curMin+questions[k].first);
    ll leave = solve(k+1, curMin);

    return dp[k][curMin] = max(take, leave);
}

int main()
{
    int n_cases; cin >> n_cases;
    for (int c = 0; c < n_cases; c++)
    {
        int n, m; cin >> n >> m;
        mins = m;
        questions = vector<pair<int,int>>();
        dp = vector<vector<ll>>(n + 10, vector<ll>(m + 10, -1));
        for (int i = 0; i < n; i++) 
        {
            int t, v; cin >> t >> v;
            questions.emplace_back(t, v);
        }
        sort(questions);
        cout << "Day #" << c + 1 << ": " << solve(0, 0) << "\n";
    }

    return 0;
}
