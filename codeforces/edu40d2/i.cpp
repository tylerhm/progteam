#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}
vd conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vd res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	rep(i,0,sz(b)) in[i].imag(b[i]);
	fft(in);
	for (C& x : in) x *= x;
	rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
	return res;
}

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

void solve() {
	string s, t; cin >> s >> t;

	vector<vector<vector<bool>>> collisions(
		6, vector<vector<bool>>(6, vector<bool>(sz(s) - sz(t) + 1)));
	for (char i = 'a'; i < 'a' + 6; i++) {
		for (char j = 'a'; j < 'a' + 6; j++) {
			if (i == j) continue;
			vd top(sz(s)), bot(sz(t));
			for (int k = 0; k < sz(s); k++) if (s[k] == i) top[k] = 1;
			for (int k = 0; k < sz(t); k++) if (t[k] == j) bot[k] = 1;
			reverse(all(bot));
			auto res = conv(top, bot);
			for (int loc = 0; loc < sz(collisions[0][0]); loc++)
				if (round(res[loc + sz(t) - 1]))
					collisions[i - 'a'][j - 'a'][loc] = true;
		}
	}

	for (int i = 0; i < sz(s) - sz(t) + 1; i++) {
		UF dsu(6);
		int cnt = 0;
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 6; k++) {
				if (collisions[j][k][i])
					if (dsu.join(j, k))
						cnt++;
			}
		}
		cout << cnt << " ";
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	// int t; cin >> t;
	// for (int tc = 1; tc <= t; tc++)
		solve();

    return 0;
}

