#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;
#define MOD 1000000007

// (n k) = (n-1 k) + (n-1 k-1)
// n == k then return 1
// or k == 0 return 1

vector<vector<int>> dp;

ll bino(ll n, ll k) {
    if (n == k || k == 0) return 1;
    if (dp[n][k] != -1) return dp[n][k]%MOD;
    return dp[n][k] = (bino(n-1, k)%MOD + bino(n-1, k-1)%MOD)%MOD;
}

void solve(int t) {
    int n, m, k, d; cin >> n >> m >> k >> d;
    int giftsAfterSpecial = (n-k);
    int nonSpecialPeople = (m-k);
    for (int i = 0; i < n; i++) {
        int g; cin >> g;
    }
    cout << giftsAfterSpecial << ' ' << nonSpecialPeople << endl;
    dp = vector<vector<int>>(giftsAfterSpecial+10, vector<int>(nonSpecialPeople+10, -1));
    ll gChooseN = bino(giftsAfterSpecial, nonSpecialPeople)%MOD;
    ll specialFact = 1;
    for (int i = 1; i <= k; i++) specialFact = (specialFact*i)%MOD;
    cout <<  gChooseN*specialFact << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt; cin >> tt;
    for (int t = 0; t < tt; t++)
        solve(t);

    return 0;
}
