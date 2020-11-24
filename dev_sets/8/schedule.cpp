#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

vector<pair<int, int>> times;
vector<vector<int>> dp;
int s;

int findMaxTime(int k, int curTime)
{
    if (k == s) return 0;
    if (dp[k][curTime] != -1) return dp[k][curTime];

    // if it's possible to take, try both
    if (times[k].first >= curTime) return dp[k][curTime] = max((times[k].second - times[k].first) + findMaxTime(k+1, times[k].second),
                                                                findMaxTime(k+1, curTime));
    // else just skip
    return dp[k][curTime] = findMaxTime(k+1, curTime);
}

int main()
{
    int n_cases; cin >> n_cases;
    for (int iter = 1; iter <= n_cases; iter++)
    {
        int n; cin >> n;

        times = vector<pair<int, int>>();
        for (int i = 0; i < n; i++)
        {
            int start, end; cin >> start >> end;
            if (start > 1020 || start < 480 || end > 1020 || end < 480) continue;
            times.emplace_back(start, end);
        }
        sort(times);
        s = times.size();
        dp = vector<vector<int>>(s+10, vector<int>(1100, -1));
        cout << findMaxTime(0, 480) << "\n";
    }
    return 0;
}
