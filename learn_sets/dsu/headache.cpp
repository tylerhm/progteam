#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

struct fight {
    int u, v, w;
    fight(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(struct fight a) {
        return w < a.w;
    }
};

struct DSU {
    vector<int> s;
    DSU(int n): s(n, -1) {}
    int find(int i) { return s[i] < 0 ? i : s[i] = find(s[i]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (s[a] > s[b]) swap(a, b);
        s[a] += s[b], s[b] = a;
        return true;
    }
    int size(int i) { return -s[find(i)]; }
    bool same(int a, int b) { return find(a) == find(b); }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m; cin >> n >> m;
    vector<int> grouped(n);
    vector<fight> fights(m, fight(0, 0, 0));
    DSU dsu = DSU(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        fights[i] = fight(u, v, w);
    }
    sort(all(fights));
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int u = fights[i].u;
        int v = fights[i].v;
        int w = fights[i].w;
        if (dsu.same(u, v)) {
            ans = w;
            break;
        }
        if (grouped[u] != -1 && grouped[v] != -1) {
            dsu.join(u, grouped[v]);
            dsu.join(v, grouped[u]);
        }
        else if (grouped[u] != -1) {
            grouped[v] = u;
            dsu.join(v, grouped[u]);
        }
        else if (grouped[v] != -1) {
            grouped[u] = v;
            dsu.join(u, grouped[v]);
        }
        else {
            grouped[u] = v;
            grouped[v] = u;
        }
    }
    cout << ans << nl;


    return 0;
}
