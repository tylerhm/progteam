#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi val, comp, z, cont;
int Time, ncomps;
template <class G, class F>
int dfs(int j, G &g, F &f)
{
    int low = val[j] = ++Time, x;
    z.push_back(j);
    for (auto e : g[j])
        if (comp[e] < 0)
            low = min(low, val[e] ?: dfs(e, g, f));
    if (low == val[j])
    {
        do
        {
            x = z.back();
            z.pop_back();
            comp[x] = ncomps;
            cont.push_back(x);
        } while (x != j);
        f(cont);
        cont.clear();
        ncomps++;
    }
    return val[j] = low;
}
template <class G, class F>
void scc(G &g, F f)
{
    int n = sz(g);
    val.assign(n, 0);
    comp.assign(n, -1);
    Time = ncomps = 0;
    rep(i, 0, n) if (comp[i] < 0) dfs(i, g, f);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int c, b; cin >> c >> b;
    
    vector<vector<int>> adjList(c);
    for (int i = 0; i < b; i++) {
        int u; cin >> u; u--;
        int m; cin >> m;
        for (int j = 0; j < m; j++) {
            int v; cin >> v; v--;
            adjList[u].push_back(v);
        }
    }

    scc(adjList, [](vi& v){});

    vector<int> ind(ncomps, 0);
    for (int u = 0; u < c; u++) {
        for (int v : adjList[u]) {
            if (comp[u] == comp[v]) continue;
            ind[comp[v]]++;
        }
    }

    int zero = -1;
    for (int i = 0; i < sz(ind); i++) {
        if (ind[i] == 0) {
            if (zero != -1) {
                cout << 0 << endl;
                return 0;
            }
            zero = i;
        }
    }

    int size = 0;
    for (int i = 0; i < c; i++) {
        if (comp[i] == zero) {
            size++;
        }
    }
    
    cout << size << endl;

    return 0;    
}
