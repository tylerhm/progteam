#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
using namespace std;

vector<vector<ll>> dp;
vector<int> wes, ps;
int n, mw;
ll oo = __LONG_LONG_MAX__ / 4;

ll solve(int i, int cw) {
    if (dp[i][cw] != -1) return dp[i][cw];
    if (i == n) return dp[i][cw] = cw == mw ? 0 : oo;
    ll minA = oo;
    for (int val = 0; cw + val * wes[i] <= mw; val++)
        minA = min(minA, val * ps[i] + solve(i + 1, cw + val * wes[i]));

    return dp[i][cw] = minA;
}

void solve(int t) {
    int p, pc; cin >> p >> pc >> n;
    mw = pc - p;

    ps = vector<int>(n);
    wes = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> ps[i];
        cin >> wes[i];
    }

    dp = vector<vector<ll>>(n+10, vector<ll>(mw+10, -1));

    // try recursive, because iterative sucks
    ll ans = solve(0, 0);

    if (ans != oo)
        cout << "The minimum amount of money in the piggy-bank is " << ans << "." << nl;
    else
        cout << "This is impossible." << nl;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int tt; cin >> tt;
	for (int t = 1; t <= tt; t++)
		solve(t);

    return 0;
}
