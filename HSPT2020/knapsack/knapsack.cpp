#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

ll reverseKnap(ll weightToRemove, vector<ll> &weights, vector<ll> &vals) {
	vector<vector<ll>> dp(vals.size()+1, vector<ll>(weightToRemove+1));

	ll minValueOver = oo;

	for (int i = 0; i <= vals.size(); i++) {
		for (int w = 0; w <= weightToRemove; w++) {
			if (i == 0 || w == 0)
				dp[i][w] = oo;
			else if (weights[i - 1] <= w) {
				if (dp[i-1][weightToRemove-weights[i-1]] == oo)
					dp[i][w] = vals[i-1];
				else
					dp[i][w] = min(vals[i-1] + dp[i-1][weightToRemove-weights[i-1]],
							   	   dp[i-1][w]);
			}
			else {
				dp[i][w] = dp[i-1][w];
				minValueOver = min(minValueOver, dp[i][w] + vals[i-1]);
			}
		}
	}

	return minValueOver;
}

void solve(int t) {
	int n, m; cin >> n >> m;

	vector<ll> vals(n), weights(n);
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
		cin >> weights[i];
	}

	// attempt to take ALL the values
	ll valSum = 0, weightSum = 0;
	for (ll v : vals) valSum += v;
	for (ll w : weights) weightSum += w;

	// if the weight sum is already safe, then just use it!
	if (weightSum <= m) {
		cout << valSum << nl;
		return;
	}

	// otherwise, find out how much weight we have to trim off
	ll weightToRemove = weightSum - m;

	// reverse knapsack -- minimize value taken with at least weightToRemove removed
	ll valToRemove = reverseKnap(weightToRemove, weights, vals);

	cout << valSum-valToRemove << nl;
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
