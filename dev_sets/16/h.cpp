#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; cin >> n;
    vector<int> vals(n);
    for (auto &v: vals) cin >> v;
    vector<bool> dp(n+1, false);

    int count = 0;
    for (int i = 0; i < n; i++) {
        dp[vals[i]] = true;
        if (!dp[vals[i]-1])
            count++;
    }
    cout << (count+1)/2 << nl;

    return 0;
}
