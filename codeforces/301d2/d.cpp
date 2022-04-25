#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

double dp[101][101][101];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
	cout << fixed << setprecision(15);

	int r, s, p;
	cin >> r >> s >> p;

	dp[r][s][p] = 1;
	for (int cr = r; cr >= 0; cr--)
		for (int cs = s; cs >= 0; cs--)
			for (int cp = p; cp >= 0; cp--) {
				if (!cr && !cs) continue;
				if (!cr && !cp) continue;
				if (!cs && !cp) continue;
				double ans = dp[cr][cs][cp];
				int wr = cr * cs;
				int ws = cs * cp;
				int wp = cp * cr;
				int tot = wr + ws + wp;
				if (cr > 0) dp[cr - 1][cs][cp] += ans * wp / tot;
				if (cs > 0) dp[cr][cs - 1][cp] += ans * wr / tot;
				if (cp > 0) dp[cr][cs][cp - 1] += ans * ws / tot;
			}

	double ar, as, ap;
	ar = as = ap = 0;
	for (int i = 1; i <= r; i++) ar += dp[i][0][0];
	for (int i = 1; i <= s; i++) as += dp[0][i][0];
	for (int i = 1; i <= p; i++) ap += dp[0][0][i];
	cout << ar << ' ' << as << ' ' << ap << "\n";

    return 0;
}

