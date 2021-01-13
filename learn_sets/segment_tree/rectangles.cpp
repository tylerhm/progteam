#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

// range xor (invert)
// range sum
// segtree with lazy propagation
struct node {
    int l, r, m, val, lazy;
    node *left, *right;
    node() {}
    node(int ll, int rr) {
        l = ll;
        r = rr;
        m = (ll+rr)/2;
        val = 0;
        lazy = 0;
        left = nullptr;
        right = nullptr;
    }
    void prop() {
        check();
        if (lazy == 1) {
            left->lazy ^= 1;
            right->lazy ^= 1;
            lazy = 0;
        }
    }
    int get() {
        if (lazy == 1)
            return (r-l+1)-val;
        return val;
    }
    void check() {
        if (left)
            return;
        left = new node(l, m);
        right = new node(m+1, r);
    }
    void update(int ll, int rr) {
        //cout << l << ' ' << r << ' ' << val << ' ' << lazy << nl;
        if (rr < l || ll > r)
            return;
        if (ll <= l && rr >= r) {
            lazy ^= 1;
            return;
        }
        prop();
        left->update(ll, rr);
        right->update(ll, rr);
        val = left->get() + right->get();
    }
    int query(int ll, int rr) {
        //cout << l << ' ' << r << ' ' << val << ' ' << lazy << nl;
        if (rr < l || ll > r)
            return 0;
        if (ll <= l && rr >= r)
            return get();

        prop();
        val = left->get() + right->get();
        return left->query(ll, rr) + right->query(ll, rr);
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    node seg(0, (int)1e9 + 10);
    vector<pair<int, pair<int, int>>> updates(0);
    for (int i = 0; i < n; i++) {
        int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
        updates.emplace_back(x1, make_pair(y1, y2));
        updates.emplace_back(x2, make_pair(y1, y2));
    }
    sort(all(updates));

    ll area = 0;
    for (int i = 0; i < updates.size() - 1; i++) {
        auto [x, p] = updates[i];
        auto [y1, y2] = p;
        cerr << "updating " << y1 << ' ' << y2 << " at " << x << nl;
        seg.update(y1+1, y2);
        area += (ll)seg.get() * (updates[i+1].first - x);
        cerr << seg.get() << nl;
    }

    cout << area << nl;

    return 0;
}
