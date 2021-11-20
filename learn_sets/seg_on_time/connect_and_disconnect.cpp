#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct RollbackUF {
    vi e; vector<pii> st; int ncomps;
    RollbackUF(int n) : e(n, -1), ncomps(n) {}
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : find(e[x]); }
    int time() { return sz(st); }
    void rollback(int t) {
        ncomps += (time() - t) / 2;
        for (int i = time(); i --> t;)
            e[st[i].first] = st[i].second;
        st.resize(t);
    }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        st.push_back({a, e[a]});
        st.push_back({b, e[b]});
        e[a] += e[b]; e[b] = a;
        ncomps--;
        return true;
    }
};

struct seg {
    int l, r, m;
    vector<pii> schrodenger;

    seg *left = nullptr, *right = nullptr;
    seg(int lo, int hi) {
        l = lo, r = hi; m = (l + r) >> 1;
        if (l != r) {
            left = new seg(l, m);
            right = new seg(m + 1, r);
        }
    }

    void logExistence(int lo, int hi, pii e) {
        if (lo > r || hi < l) return;
        if (lo <= l && hi >= r)
            schrodenger.push_back(e);
        else {
            left->logExistence(lo, hi, e);
            right->logExistence(lo, hi, e);
        }
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    // freopen("connect.in", "r", stdin), freopen("connect.out", "w", stdout);

    int n, k; cin >> n >> k;

    seg s(0, k);
    set<int> toAns;
    map<pii, int> edgeToStart;
    for (int i = 0; i < k; i++) {
        char type; cin >> type;
        if (type == '?') toAns.insert(i);
        else {
            int a, b; cin >> a >> b;
            a--; b--;
            pii e = minmax(a, b);
            if (type == '+') edgeToStart[e] = i;
            else {
                s.logExistence(edgeToStart[e], i, e);
                edgeToStart.erase(e);
            }
        }
    }

    for (auto &p : edgeToStart)
        s.logExistence(p.second, s.r, p.first);

    RollbackUF dsu(n);
    auto dfs = [&](seg *s, auto &&dfs) -> void {
        int t = dsu.time();
        for (auto q : s->schrodenger)
            dsu.join(q.first, q.second);

        if (s->l == s->r && toAns.count(s->l))
            cout << dsu.ncomps << nl;

        if (s->left != nullptr) {
            dfs(s->left, dfs);
            dfs(s->right, dfs);
        }

        dsu.rollback(t);
    };

    // traverse the tree 0.o
    dfs(&s, dfs);

    return 0;
}