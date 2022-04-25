#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <list>
#include <numeric>
#include <random>
#include <tuple>
#include <map>
#include <set>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 10'007;

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}


ll inv(ll n) {
	return modpow(n, mod-2);
}

void gaussian_mod(vector<vector<ll>> &m) {
	int R = sz(m), C = sz(m[0]);
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			m[i][j] %= mod;
	for (int pr = 0, pc = 0; pr < R && pc < C; pc++) {
		int sr = pr;
		for (int j = pr + 1; j < R; j++)
			if (abs(m[j][pc]) > abs(m[sr][pc]))
				sr = j;
		if (m[sr][pc] == 0) continue;
		swap(m[sr], m[pr]);
		// assert(m[pr][pc] >= 0);
		ll piv = inv(m[pr][pc]);
		for (int j = pc; j < C; j++)
			m[pr][j] = (m[pr][j] * piv) % mod;
		for (int i = 0; i < R; i++) {
			if (i == pr) continue;
			ll ratio = -m[i][pc];
			for (int k = pc; k < C; k++) {
				m[i][k] += m[pr][k] * ratio;
				m[i][k] = ((m[i][k] % mod) + mod) % mod;
			}
		}
		pr++;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, d, w, l; cin >> n >> d >> w >> l;
	vi status(n, 0); // 1 win 2 lose 0 none
	for (int i = 0; i < w; i++) {
		int idx; cin >> idx; idx--;
		status[idx] = 1;
	}
	for (int i = 0; i < l; i++) {
		int idx; cin >> idx; idx--;
		status[idx] = 2;
	}

	// E(w) = 1
	// E(l) = 0
	// E(x) = (1/d * E(x+1)) + ... x+d
	vector<vector<ll>> mat(n, vector<ll>(n+1, 0));
	for (int i = 0; i < n; i++) {
		mat[i][i] = 1;
		if (status[i] == 1) mat[i].back() = 1;
		else {
			mat[i].back() = 0;
			if (status[i] == 0)
				for (int x = i + 1; x <= i + d; x++)
					(mat[i][x % n] -= inv(d)) %= mod;
		}
	}

	gaussian_mod(mat);
	cout << mat[0].back() << endl;

	return 0;
}

