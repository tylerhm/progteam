#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int t) {
	int n, m; cin >> n >> m;
	ll a[n];
	for (int i = 0; i < n; i++) {
		ll val; cin >> val;
		val = pow(10, val);
		a[i] = val;
	}

	m++;
	ll canHave[n];
	for (int i = 0; i < n - 1; i++)
		canHave[i] = (a[i+1] / a[i]) - 1;
	canHave[n-1] = LLONG_MAX;

	ll left = m;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += min(left, canHave[i]) * a[i];
		left -= canHave[i];
		if (left <= 0) break;
	}

	cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++)
		solve(tt);

    return 0;
}

