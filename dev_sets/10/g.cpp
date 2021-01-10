#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

vector<int> dp;
vector<int> times;
int n;

void flipBit(int * num, int bit)
{
    *num = *num - (1 << (bit - 1));
}

// l 10011100
// r 01100011

int solve(int state)
{
    if (dp[leftState] != -1)
        return dp[leftState];

    if (leftState == 0) return 0;

    
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> n;
    
    times = vector<int>(n);
    for (int i = 0; i < n; i++) cin >> times[i];

    dp = vector<vector<int>>(n, vector<int>(n, -1));

    cout << total << endl;

    return 0;
}
