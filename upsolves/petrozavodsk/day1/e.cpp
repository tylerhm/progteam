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

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UF {
	vi e;
    vector<pii> highest; // [depth, node]
	UF(int n, vi &depths) : e(n, -1), highest(n) {
        for (int i = 0; i < n; i++)
            highest[i] = {depths[i], i};
    }
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
        highest[a] = min(highest[a], highest[b]);
		return true;
	}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int N, M; cin >> N >> M;
    vector<tuple<int, int, int>> edgeList;
    vector<vi> mst(N);
    map<pii, int> edgeToID;

    for (int i = 0; i < M; i++) {
        int a, b, m; cin >> a >> b >> m;
        a--, b--;
        if (a > b) swap(a, b);
        edgeList.emplace_back(a, b, m);
        edgeToID[{a, b}] = i;
        if (m) {
            mst[a].push_back(b);
            mst[b].push_back(a);
        }
    }

    vi pars(N), depths(N);
    pars[0] = 0; depths[0] = 0;
    auto dfs = [&](int cur, int par, int depth, auto &&dfs) -> void {
        pars[cur] = par;
        depths[cur] = depth;
        for (auto x : mst[cur])
            if (x != par)
                dfs(x, cur, depth + 1, dfs);
    };
    dfs(0, -1, 0, dfs);

    UF dsu(N, depths);
    vi ans(M, -1);
    int curVal = 1;
    for (int i = 0; i < M; i++) {
        auto &[a, b, m] = edgeList[i];
        // Place immediately
        if (m) {
            if (dsu.join(a, b))
                ans[i] = curVal++;
        }
        // Connecting blue edge
        else {
            int aDep = depths[a];
            int bDep = depths[b];
            int aMove = a, bMove = b;
            vi toPlace;
            // While a and are not together
            while (!dsu.sameSet(a, b)) {
                // If aDep is < bDep, then move it up
                if (aDep > bDep) {
                    // Valid edge join
                    if (dsu.join(aMove, pars[aMove]))
                        toPlace.push_back(edgeToID[minmax(aMove, pars[aMove])]);
                    aMove = dsu.highest[dsu.find(aMove)].second;
                    // assert(aDep != dsu.highest[dsu.find(aMove)].first);
                    aDep = dsu.highest[dsu.find(aMove)].first;
                } else {
                    // Valid edge join
                    if (dsu.join(bMove, pars[bMove]))
                        toPlace.push_back(edgeToID[minmax(bMove, pars[bMove])]);
                    bMove = dsu.highest[dsu.find(bMove)].second;
                    // assert(bDep != dsu.highest[dsu.find(bMove)].first);
                    bDep = dsu.highest[dsu.find(bMove)].first;
                }
            }
            sort(all(toPlace));
            for (auto x : toPlace)
                ans[x] = curVal++;
            ans[i] = curVal++;
        }
    }

    for (auto x : ans) cout << x << ' ';
    cout << endl;

    return 0;
}
