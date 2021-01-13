#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

pair<int, int> pairMin(pair<int, int> a, pair<int, int> b) {
    return a.second<b.second?a:b;
}
pair<int, int> pairMax(pair<int, int> a, pair<int, int> b) {
    return a.second<b.second?b:a;
}

// stores
// {idx, val}
// range min and max
int nodeNum = 0;
struct node {
    int l, r, m;
    pair<int, int> mn, mx;
    node *left, *right;
    node() {}
    node(int ll, int rr) {
        l = ll;
        r = rr;
        m = (ll+rr)/2;
        mn = {oo, oo};
        mx = {-oo, -oo};
        if (ll == rr) return;
        left = new node(ll, m);
        right = new node (m + 1, rr);
    }
    void set(int idx, int ogIdx, int nval) {
        if (l == r) {
            mn = {ogIdx, nval};
            mx = {ogIdx, nval};
            return;
        }
        if (idx <= m) 
            left->set(idx, ogIdx, nval);
        else
            right->set(idx, ogIdx, nval);
        mn = pairMin(left->mn, right->mn);
        mx = pairMax(left->mx, right->mx);
    }
    pair<int, int> queryMin(int ll, int rr) {
        if (rr < l || ll > r)
            return {oo, oo};
        if (ll <= l && rr >= r)
            return mn;
        return pairMin(left->queryMin(ll, rr), right->queryMin(ll, rr));
    }
    pair<int, int> queryMax(int ll, int rr) {
        if (rr < l || ll > r)
            return {-oo, -oo};
        if (ll <= l && rr >= r)
            return mx;
        return pairMax(left->queryMax(ll, rr), right->queryMax(ll, rr));
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, q; cin >> n >> q;
    node xSeg = node(1, n);
    node ySeg = node(1, n);
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        xSeg.set(i, i, x);
        ySeg.set(i, i, y);
    }

    for (int i = 1; i <= q; i++) {
        int lo, hi; cin >> lo >> hi;
        auto xMin = xSeg.queryMin(lo, hi);
        auto xMax = xSeg.queryMax(lo, hi);
        auto yMin = ySeg.queryMin(lo, hi);
        auto yMax = ySeg.queryMax(lo, hi);

        vector<int> dontUse = {xMin.first, xMax.first, yMin.first, yMax.first};

        // we have indexes that we dont want to use.
        // now find new mins and maxes EXCLUDING that value
        ll side = LLONG_MAX;
        for (int idx : dontUse) {
            ll xMinNew = pairMin(xSeg.queryMin(lo, idx-1), xSeg.queryMin(idx+1, hi)).second;
            ll xMaxNew = pairMax(xSeg.queryMax(lo, idx-1), xSeg.queryMax(idx+1, hi)).second;
            ll yMinNew = pairMin(ySeg.queryMin(lo, idx-1), ySeg.queryMin(idx+1, hi)).second;
            ll yMaxNew = pairMax(ySeg.queryMax(lo, idx-1), ySeg.queryMax(idx+1, hi)).second;
            side = min(side, max(xMaxNew-xMinNew, yMaxNew-yMinNew));
        }

        cout << side << nl;
    }

    return 0;
}
