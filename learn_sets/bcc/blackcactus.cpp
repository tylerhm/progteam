#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi num, st;
vector<vector<pii>> ed;
int Time;
template<class F>
int dfs(int at, int par, F& f) {
	int me = num[at] = ++Time, e, y, top = me;
	for (auto pa : ed[at]) if (pa.second != par) {
		tie(y, e) = pa;
		if (num[y]) {
			top = min(top, num[y]);
			if (num[y] < me)
				st.push_back(e);
		} else {
			int si = sz(st);
			int up = dfs(y, e, f);
			top = min(top, up);
			if (up == me) {
				st.push_back(e);
				f(vi(st.begin() + si, st.end()));
				st.resize(si);
			}
			else if (up < me) st.push_back(e);
			else { /* e is a bridge */ }
		}
	}
	return top;
}

template<class F>
void bicomps(F f) {
	num.assign(sz(ed), 0);
	st.clear();
	Time = 0;
	rep(i,0,sz(ed)) if (!num[i]) dfs(i, -1, f);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		int n, m; cin >> n >> m;

		int eid = 0; ed.assign(n, vector<pii>(0));
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			a--; b--;
			ed[a].emplace_back(b, eid);
			ed[b].emplace_back(a, eid++);
		}

		ll ans = 1;
		bicomps([&](const vi &edgeList) {
			ans = (ans * sz(edgeList)) % 1007;
		});
		cout << "Case #" << tt << ": " << ans << nl << nl;
	}


	return 0;
}

