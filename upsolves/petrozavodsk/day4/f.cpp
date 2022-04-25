#include <iostream>
#include <assert.h>
#include <iomanip>
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

typedef vector<double> vd;
const double eps = 1e-12;

int solveLinear(vector<vd>& A, vd& b, vd& x) {
	int n = sz(A), m = sz(x), rank = 0, br, bc;
	if (n) assert(sz(A[0]) == m);
	vi col(m); iota(all(col), 0);

	rep(i,0,n) {
		double v, bv = 0;
		rep(r,i,n) rep(c,i,m)
			if ((v = fabs(A[r][c])) > bv)
				br = r, bc = c, bv = v;
		if (bv <= eps) {
			rep(j,i,n) if (fabs(b[j]) > eps) return -1;
			break;
		}
		swap(A[i], A[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		rep(j,0,n) swap(A[j][i], A[j][bc]);
		bv = 1/A[i][i];
		rep(j,i+1,n) {
			double fac = A[j][i] * bv;
			b[j] -= fac * b[i];
			rep(k,i+1,m) A[j][k] -= fac*A[i][k];
		}
		rank++;
	}

	x.assign(m, 0);
	for (int i = rank; i--;) {
		b[i] /= A[i][i];
		x[col[i]] = b[i];
		rep(j,0,i) b[j] -= A[j][i] * b[i];
	}
	return rank; // (multiple solutions if rank < m)
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << fixed << setprecision(9);

	int n, k; cin >> n >> k;
	double p; cin >> p;
	double q = (1 - p);

	// E(<bitstring>) = Expected number of moves to win
	// E(000) = p(E(001) + 1) + q(E(000) + 1)
	// E(000) = pE(001) + p + qE(000) + q
	// E(000) - pE(001) - pE(000) = 1
	// Num vars in Gaussian = 2^n

	int bound = 1 << n;
	vector<vd> A(bound, vd(bound));
	vd b(bound);

	int killSigBitMask = (1 << n) - 1;
	for (int mask = 0; mask < bound; mask++) {
		A[mask][mask] = 1;

		if (__builtin_popcount(mask) >= k)
			continue;

		int shifted = (mask << 1) & killSigBitMask;
		A[mask][shifted | 1] -= p;
		A[mask][shifted] -= q;
		b[mask] = 1;
	}

	vd x(bound);
	solveLinear(A, b, x);
	cout << x[0] << endl;

	return 0;
}

