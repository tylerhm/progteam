#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool on(int &mask, int &bit) { return (mask & (1 << bit)); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
	cout << fixed << setprecision(15);

	int N; cin >> N;
	vector<double> p(N);
	for (auto &x : p)
		cin >> x;

	vector<double> dp((1 << N), -1);
	auto go = [&](int mask, auto &&go) -> double {
		if (__builtin_popcount(mask) == 2)
			return 0;

		auto &ans = dp[mask];
		if (ans >= 0) return ans;

		// For all child-deaths
		double num = 1;
		double den = 0;
		for (int b = 0; b < N; b++) {
			if (!on(mask, b)) continue;
			double diesUp = p[b], diesDown = (1 - p[b]);
			for (int o = 0; o < N; o++) {
				if (o != b && on(mask, o)) {
					diesUp *= (1 - p[o]);
					diesDown *= p[o];
				}
			}
			double dies = diesUp + diesDown;
			num += dies * go(mask ^ (1 << b), go);
			den += dies;
		}

		return ans = num / den;
	};

	cout << go((1 << N) - 1, go) << "\n";

    return 0;
}

