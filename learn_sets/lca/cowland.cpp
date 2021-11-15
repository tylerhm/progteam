#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j, 0, sz(jmp[k]))
                jmp[k][j] = min(jmp[k-1][j], jmp[k-1][j+pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b);
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

template<class T>
struct Tree {
    static constexpr T unit = 0;
    T f(T a, T b) { return a ^ b; }
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

vector<vi> adjList;
vector<ll> attractions;
map<int, int> rmqLocs;
map<int, pii> segLocs;
vector<pii> lcaVec;
vector<ll> plusMinus;

void traverse(int node, int parent, int depth) {
    segLocs[node].first = sz(plusMinus);
    plusMinus.push_back(attractions[node]);

    rmqLocs[node] = sz(lcaVec);
    lcaVec.emplace_back(depth, node);

    for (auto child : adjList[node])
        if (child != parent) {
            traverse(child, node, depth + 1);
            lcaVec.emplace_back(depth, node);
        }

    segLocs[node].second = sz(plusMinus);
    plusMinus.push_back(attractions[node]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, q; cin >> n >> q;
    adjList.resize(n);
    attractions.resize(n);
    for (auto &x : attractions) cin >> x;

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    traverse(0, -1, 0);
    Tree<ll> seg(sz(plusMinus));
    for (int i = 0; i < sz(plusMinus); i++)
        seg.update(i, plusMinus[i]);

    RMQ<pii> rmq(lcaVec);
    for (int i = 0; i < q; i++) {
        int type, u, v; cin >> type >> u >> v;
        u--; v--;
        if (type == 1) {
            auto locs = segLocs[u];
            int a = locs.first;
            int b = locs.second;
            seg.update(a, v+1);
            seg.update(b, v+1);
            attractions[u] = v+1;
        } else {
            auto uLoc = segLocs[u];
            auto vLoc = segLocs[v];

            int rmqLo = min(rmqLocs[u], rmqLocs[v]);
            int rmqHi = max(rmqLocs[u], rmqLocs[v]);

            int a = uLoc.first;
            int b = vLoc.first;

            int lca = rmq.query(rmqLo, rmqHi).second;

            ll dist = 0;
            dist ^= seg.query(0, a+1);
            dist ^= seg.query(0, b+1);
            dist ^= attractions[lca];

            cout << dist << endl;
        }
    }

    return 0;
}
