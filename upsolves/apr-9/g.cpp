#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
	cout << fixed << setprecision(1);

	int n; cin >> n;
	ll d; cin >> d;

	vector<ll> forwards(n), backwards(n);
	for (int i = 0; i < n; i++) {
		ll val; cin >> val;
		forwards[i] = val - i * d;
		backwards[i] = val + i * d;
	}

	long double ans = min((*max_element(all(forwards)) - *min_element(all(forwards))),
						  (*max_element(all(backwards)) - *min_element(all(backwards))))
		/ (long double)2;

	cout << ans << "\n";

    return 0;
}

