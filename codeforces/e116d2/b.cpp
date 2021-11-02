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
	ll n, k; cin >> n >> k;

	if (n == 1) {
		cout << 0 << endl;
		return;
	}

	ll time = 0;
	ll copied = 1;
	while (copied < k) {
		copied *= 2;
		time++;
	}

	ll leftOver = n - copied;
	ll timeLeft = ceil((double)leftOver / k);

	cout << time+timeLeft << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++)
		solve(tt);

    return 0;
}

