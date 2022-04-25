#include <bits/stdc++.h>
using namespace std;

// #define MULTI
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class I> vi lis(const vector<I>& S) {
	if (S.empty()) return {};
	vi prev(sz(S));
	typedef pair<I, int> p;
	vector<p> res;
	rep(i,0,sz(S)) {
		// change 0 -> i for longest non-decreasing subsequence
		auto it = lower_bound(all(res), p{S[i], i});
		if (it == res.end()) res.emplace_back(), it = res.end()-1;
		*it = {S[i], i};
		prev[i] = it == res.begin() ? 0 : (it-1)->second;
	}
	int L = sz(res), cur = res.back().second;
	vi ans(L);
	while (L--) ans[L] = cur, cur = prev[cur];
	return ans;
}

void solve(int tc) {
	ll n, r, w, h; cin >> n >> r >> w >> h;
	vector<pair<ll, ll>> points(n);
	for (auto &p : points) {
		ll x, y; cin >> x >> y;
		p = { x*r + y, y - x*r };
	}
	sort(all(points));
	vector<ll> ys;
	for (auto &[_, y] : points)
		ys.push_back(y);
	cout << sz(lis(ys)) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int tc = 1;
#ifdef MULTI
	int t; cin >> t;
	for (; tc <= t; tc++)
#endif
		solve(tc);

    return 0;
}

