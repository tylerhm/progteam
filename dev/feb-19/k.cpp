#include <climits>
#include <iomanip>
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
#include <cfloat>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct planet {
	int x, y, z;
	planet() {}
	planet(int x, int y, int z) : x(x), y(y), z(z) {}
	long double dist(const planet &a) const {
		ll dx = x - a.x;
		ll dy = y - a.y;
		ll dz = z - a.z;
		return sqrtl(dx*dx + dy*dy + dz*dz);
	}
};

vector<planet> planets;
long double dp[2][18][(1 << 18) + 10];
int N;

long double go(bool tookFirst, bool tookPortal, int curLoc, int mask) {
	if (mask == (1 << N) - 1) {
		if (tookPortal || tookFirst)
			return planets[curLoc].dist(planets[0]);
		return 0;
	}

	auto &ans = dp[tookPortal][curLoc][mask];
	if (ans != -1) return ans;

	ans = DBL_MAX;
	for (int b = 0; b < N; b++)
		if (!(mask & (1 << b))) {
			ans = min(ans, go(tookFirst, false, b, mask | (1 << b)) + planets[curLoc].dist(planets[b]));
			if (!tookPortal)
				ans = min(ans, go(curLoc == 0 ? true : tookFirst, true, b, mask | (1 << b)));
		}

	return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
	cout << fixed << setprecision(9);

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 18; j++)
			for (int k = 0; k < (1 << 18) + 10; k++)
				dp[i][j][k] = -1;

	cin >> N;
	planets.resize(N);
	for (auto &[x, y, z] : planets) cin >> x >> y >> z;

	cout << min(go(false, false, 0, 0), go(true, true, 0, 0)) << endl;

    return 0;
}

