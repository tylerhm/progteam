#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<ll> fib;

void precomp() {
	fib.push_back(1);
	fib.push_back(1);
	while (fib.back() <= (ll)1e18)
		fib.push_back(fib[sz(fib) - 1] + fib[sz(fib) - 2]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	precomp();

	int n, m; cin >> n >> m;
	vi vals(n);
	for (auto &x : vals) cin >> x;
	vector<vi> adj(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vi dp(n);
	auto go = [&](int idx, int dist, auto &&go) {
		// try to go to either
	};

	return 0;
}

