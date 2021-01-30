#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;
#define MOD 1000000007

#define nowall 18
#define onewall 6
#define twowall 2

void solve(int t) {
	int r, c; cin >> r >> c;
	ll ans = 1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i == 0 && j == 0)
				ans = (ans*nowall)%MOD;
			else if (i == 0 || j == 0)
				ans = (ans*onewall)%MOD;
			else
				ans = (ans*twowall)%MOD;
		}
	}
	cout << ans%MOD << nl;
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
