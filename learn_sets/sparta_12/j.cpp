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
    ll l, r, m, val, lazy;
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
    ll get() {
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

    int n, a; cin >> n >> a;
    node implicit_seg = node(0, (ll)n*n);
    int dxs[] = {-1, 1, 1, -1};
    int dys[] = {1, 1, -1, -1};
    int moveStartX[] = {-1, 0, 0, -1};
    int moveStartY[] = {0, 0, -1, -1};
    for (int i = 0; i < a; i++) {
        int row, col, pow, ori; cin >> row >> col >> pow >> ori;
        pow--;
        row += moveStartY[ori];
        col += moveStartX[ori];
        int dx = dxs[ori], dy = dys[ori];
        int width = pow;
        int curY = row;
        int mathedRow;
        // cout << curY << nl;
        while (width >= 0 && (curY >= 0 && curY < n)) {
            mathedRow = curY*n+col;
            if (dx == 1)
                implicit_seg.update(mathedRow, min(mathedRow+width, (curY+1)*n-1));
            else
                implicit_seg.update(max(mathedRow-width, curY*n), mathedRow);
            width--;
            curY += dy;
        }
    }
    cout << implicit_seg.get() << nl;

    return 0;
}
