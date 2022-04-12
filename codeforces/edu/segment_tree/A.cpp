#include <bits/stdc++.h>

using namespace std;

struct seg {
    long long l, r, m, val;
    seg *left, *right;
    seg(int L, int R, vector<int> &V) {
        l = L;
        r = R;
        m = (l + r) >> 1;

        if (l == r) {
            val = V[l];
        } else {
            left = new seg(L, m, V);
            right = new seg(m+1, R, V);
            val = left->val + right->val;
        }
    }

    void set(int idx, int nval) {
        if (l == r) {
            val = nval;
            return;
        } else if (idx <= m) left->set(idx, nval);
        else right->set(idx, nval);

        val = left->val + right->val;
    }

    long long query(int L, int R) {
        if (L > r || R < l) return 0;
        if (L <= l && R >= r) return val;
        return left->query(L, R) + right->query(L, R);
    }
};

int main() {
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    seg s(0, n-1, arr);
    for (int i = 0; i < q; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 1) s.set(b, c);
        else cout << s.query(b, c-1) << endl;
    }

    return 0;
}
