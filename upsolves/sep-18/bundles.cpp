#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct bundle {
    vi contained;
    unordered_set<int> search;
    ll price;
    bundle(vi b, ll p) : contained(b), search(all(b)), price(p) {}
    bool operator<(bundle &o) {
        return sz(contained) < sz(o.contained);
    }
    bool overlaps(bundle o) {
        for (int i : o.contained)
            if (search.count(i))
                return true;
        return false;
    }
};

vector<vi> adjList;
vector<bundle> bundles;

ll go(int idx) {
    // if children don't cover full range, we have to take
    unordered_set<int> found;
    for (int v : adjList[idx])
        for (int i : bundles[v].contained)
            found.insert(i);

    bool fullCover = true;
    for (int c : bundles[idx].contained)
        if (!found.count(c)) {
            fullCover = false;
            break;
        }

    if (!fullCover) return bundles[idx].price;

    // otherwise take min(self, all kids)
    ll cost = 0;
    for (int i : adjList[idx])
        cost += go(i);
    
    return min(cost, bundles[idx].price);
}

void solve() {
    int n, m; cin >> n >> m;

    bundles = vector<bundle>();
    for (int i = 0; i < m; i++) {
        ll price, num; cin >> price >> num;

        vi b(num);
        for (auto &c : b) cin >> c, c--;
        bundles.emplace_back(b, price);
    }

    sort(all(bundles));
    adjList = vector<vi>(m);
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (bundles[j].overlaps(bundles[i])) {
                adjList[j].push_back(i);
                break;
            }
        }
    }

    vector<int> ind(m);
    for (int u = 0; u < m; u++) {
        for (int v : adjList[u]) {
            ind[v]++;
        }
    }

    vi indZero;
    for (int i = 0; i < m; i++)
        if (!ind[i]) indZero.push_back(i);

    ll cost = 0;
    for (int i : indZero)
        cost += go(i);

    cout << cost << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int i = 0; i < t; i++)
        solve();

    return 0;
}
