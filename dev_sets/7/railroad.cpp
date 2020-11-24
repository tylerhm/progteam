#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int n1, n2, n3;
vector<int> t1, t2, t3;
vector<vector<int>> dp;

bool solve(int t1i, int t2i, int t3i)
{
    if (t3i == n3) return true;

    if (dp[t1i][t2i] != -1)
        return dp[t1i][t2i];

    if (t1i < n1 && t1[t1i] == t3[t3i] &&
        t2i < n2 && t2[t2i] == t3[t3i])
        return dp[t1i][t2i] = (solve(t1i+1, t2i, t3i+1) || (solve(t1i, t2i+1, t3i+1)));

    if (t1i < n1 && t1[t1i] == t3[t3i]) return dp[t1i][t2i] = solve(t1i+1, t2i, t3i+1);
    if (t2i < n2 && t2[t2i] == t3[t3i]) return dp[t1i][t2i] = solve(t1i, t2i+1, t3i+1);
    return dp[t1i][t2i] = false;
}

int main()
{
    cin >> n1 >> n2;
    while (!(n1 == 0 && n2 == 0))
    {
        t1 = vector<int>(n1);
        t2 = vector<int>(n2);

        for (int i = 0; i < n1; i++) cin >> t1[i];
        for (int i = 0; i < n2; i++) cin >> t2[i];

        n3 = n1 + n2;
        t3 = vector<int>(n3);
        for (int i = 0; i < n3; i++) cin >> t3[i];

        dp = vector<vector<int>>(n1+10, vector<int>(n2+10, -1));
        cout << (solve(0, 0, 0)? "possible\n": "not possible\n");

        cin >> n1 >> n2;
    }
    return 0;
}
