#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct rollbackDSU {
    vi e; vector<pii> st; int ncomp;
    rollbackDSU (int n) : e(n, -1), ncomp(n) {}
    int find(int a) { return e[a] < 0 ? a : e[a] = find(e[a]); }
    int time() { return sz(st); }
    void rollback(int t) {
        int dist = time() - t; ncomp += dist / 2;
        for (int i = time(); i --> t;)
            e[st[i].first] = st[i].second;
        st.resize(t);
    }
    bool join(int a, int b) {
        if ((a = find(a)) == (b = find(b))) return false;
        if (e[b] < e[a]) swap(a, b);
        st.emplace_back(a, e[a]);
        st.emplace_back(b, e[b]);
        e[a] += e[b]; e[b] = a; ncomp--;
        return true;
    }
};

struct edge {
    int a, b;
};

struct seg {
    int l, r, m;
    vector<edge> schrodenger;

    seg *left, *right;
    seg(int lo, int hi) {
        l = lo, r = hi; m = (l + r) >> 1;
        if (l != r) {
            left = new seg(l, m);
            right = new seg(m + 1, r);
        }
    }

    void logExistence(int lo, int hi, edge e) {
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

    int n, k; cin >> n >> k;

    seg s(0, n);
    rollbackDSU dsu(n);

    map<edge, pii> existence;
    vi toAns;
    for (int i = 0; i < k; i++) {
        char type; cin >> type;
        if (type == '?') toAns.push_back(i);
        else {
            int a, b; cin >> a >> b;
            a--; b--; auto p = make_pair(a, b);
            if (type == '+') {
                if (existence.count(p)) {

                }
            }
        }
    }

    return 0;
}

