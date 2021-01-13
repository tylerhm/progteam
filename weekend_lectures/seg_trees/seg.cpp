#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

// addition segtree with lazy propagation
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
        if (ll == rr) return;
        left = new node(ll, m);
        right = new node (m + 1, rr);
    }
    void prop() {
        left->lazy += lazy;
        right->lazy += lazy;
        lazy = 0;
    }
    int get() {
        return (r-l+1)*lazy + val;
    }
    void update(int ll, int rr, int delta) {
        //cout << l << ' ' << r << ' ' << val << ' ' << lazy << nl;
        if (rr < l || ll > r)
            return;
        if (ll <= l && rr >= r) {
            lazy += delta;
            return;
        }
        prop();
        left->update(ll, rr, delta);
        right->update(ll, rr, delta);
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
        if (ll == rr) return;
        left = new node(ll, m);
        right = new node (m + 1, rr);
    }
    void prop() {
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

    node seg(0, 10);
    seg.update(0, 5, 1);
    seg.update(1, 6, 2);
    seg.update(3, 7, 4);
    cout << seg.query(0, 5) << nl;
    cout << seg.query(3, 7) << nl;

    return 0;
}
