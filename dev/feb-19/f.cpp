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
#include <iomanip>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int r, n; cin >> r >> n;

	double curRad = r;
	long double curMult = 1;
	double ans = 0;
	for (int iter = 0; iter < n; ++iter) {
		if (iter == 0) curMult *= 1;
		else if (iter == 1) curMult *= 4;
		else curMult *= 3;
		ans += curMult * (M_PI * curRad * curRad);
		curRad /= 2;
	}

	cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
	cout << fixed << setprecision(9);

	int t; cin >> t;
	rep(tc,0,t) solve();

    return 0;
}

