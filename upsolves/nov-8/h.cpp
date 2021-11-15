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

	int n, m; cin >> n >> m;
	vi hats(m);
	for (auto &x : hats) cin >> x;
	int curHat = hats[0];

	vi hatLoc(n+1), order(n-1);
	vector<pii> hookFreq(n-1);
	for (int i = 1, hat = 1; i < n; i++, hat++) {
		hatLoc[i] = i == curHat ? 0 : i;
		if (hat-1 == curHat) hat++;
		order[i-1] = hat;
		hookFreq[i-1].second = i-1;
	}

	for (int i = 1; i < m; i++) {
		int nextHatLoc = hatLoc[hats[i]];
		assert(nextHatLoc != 0);
		hookFreq[nextHatLoc - 1].first++;
		hatLoc[curHat] = nextHatLoc;
		hatLoc[hats[i]] = 0;
		curHat = hats[i];
	}

	sort(all(hookFreq));
	reverse(all(hookFreq));

	ll totalDist = 0;
	vi ans;
	int curDist = 1;
	for (auto &[freq, hook] : hookFreq) {
		totalDist += freq * curDist++;
		ans.push_back(order[hook]);
	}

	cout << totalDist << nl;
	for (auto h : ans) cout << h << ' ';
	cout << endl;

    return 0;
}

