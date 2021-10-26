#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pii> compress(vector<pii> arr) {
	vector<pii> comp;
	int i = 0;
	for (; i < sz(arr); i++) {
		int start = arr[i].first;
		int end = arr[i].second;
		while (i + 1 < sz(arr) && arr[i + 1].first <= end) {
			end = max(end, arr[i + 1].second);
			i++;
		}
		comp.emplace_back(start, end);
	}
	return comp;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int l, n; cin >> l >> n;
	vector<pii> forwards, backwards;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		if (x < y) forwards.emplace_back(x, y);
		else backwards.emplace_back(y, x);
	}

	sort(all(forwards));
	sort(all(backwards));
	forwards = compress(forwards);
	backwards = compress(backwards);

	if (sz(backwards) == 0) {
		cout << forwards.back().second - forwards[0].first;
		return 0;
	}

	if (sz(forwards) == 0) {
		cout << backwards.back().second - backwards[0].first;
		return 0;
	}

	vector<ll> prefixMiddleDist(sz(backwards) + 1);
	for (int i = 0; i < sz(backwards); i++)
		prefixMiddleDist[i + 1] =
			prefixMiddleDist[i] + 2*(backwards[i].second - backwards[i].first);

	ll forwardsDist = forwards.back().second - forwards[0].first;
	ll frontChunk = abs(forwards[0].first - backwards[0].first);
	ll backChunk = abs(forwards.back().second - backwards.back().second);
	ll bestDist = INT_MAX;
	for (int s = 0; s < sz(backwards); s++) {
		for (int t = 0; t <= sz(backwards) - s; t++) {
			ll extraFirst = s == 0 ? 0 :
				frontChunk + (backwards[s - 1].second - backwards[0].first);
			ll extraBetween =
				prefixMiddleDist[sz(backwards) - t] -
				prefixMiddleDist[s];
			ll extraLast = t == 0 ? 0 :
				backChunk + (backwards.back().second - backwards[sz(backwards) - t].first);
		}
	}

	cout << bestDist << nl;

	return 0;
}

