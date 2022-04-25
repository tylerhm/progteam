#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct node {
    ll l, r, m;
    ll val = 0;

    node *lc = nullptr, *rc = nullptr;
    node(int ll, int rr) {
        l = ll;
        r = rr;
        m = ll + rr >> 1;
    }
    void makeKids() {
        lc = new node(l, m);
        rc = new node(m + 1, r);
    }

    ll query(int ll, int rr) {
        if (ll > rr) return 0;
        // no cover
        if (ll > r || rr < l) return 0;

        // full cover
        if (ll <= l && rr >= r) {
            return val;
        }

        // partial cover
        if (!lc) makeKids();
        return max(lc->query(ll, rr), rc->query(ll, rr));
    }
    void set(int idx, ll x) {

        if (l == r) {
            val = x;
            return;
        }

        if (!lc) makeKids();
        if (idx <= m) {
            lc->set(idx, x);
        } else rc->set(idx, x);

        val = max(lc->val, rc->val);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    node seg(0, 1'000'000'000);

    int n, k; cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int inp; cin >> inp;

        seg.set(inp, max(seg.query(0, inp-k), seg.query(inp+k, seg.r)) + 1);
    }

    cout << seg.val << endl;

    return 0;
}
