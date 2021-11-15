#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct info {
    int val[2] = {1, 0};
    int lazy = 0;
    int leftType = 0, rightType = 0;
    int leftRun = 1, rightRun = 1;
};

struct seg {
    int lo, hi, mid;
    info meta;
    seg *left = nullptr, *right = nullptr;

    seg(int l, int r, string &config) {
        lo = l; hi = r; mid = (lo + hi) >> 1;
        if (lo != hi) {
            left = new seg(lo, mid, config);
            right = new seg(mid + 1, hi, config);
            merge();
        } else {
            meta.lazy = config[lo] == 'S';
        }
    }

    void print() {
        cout << meta.val[!meta.lazy] << ' ' << meta.val[meta.lazy] << nl;
    }

    void prop() {
        if (meta.lazy) {
            left->meta.lazy ^= 1;
            right->meta.lazy ^= 1;
            meta.lazy = 0;
        }
    }

    void merge() {
        int actualLL = left->meta.leftType ^ left->meta.lazy;
        int actualLR = left->meta.rightType ^ left->meta.lazy;
        int actualRL = right->meta.leftType ^ right->meta.lazy;
        int actualRR = right->meta.rightType ^ right->meta.lazy;

        meta.leftType = actualLL;
        meta.rightType = actualRR;

        meta.leftRun = left->meta.leftRun;
        if (actualLL == actualRL && left->meta.leftRun == (left->hi - left->lo + 1))
            meta.leftRun += right->meta.leftRun;

        meta.rightRun = right->meta.rightRun;
        if (actualRR == actualLR && right->meta.rightRun == (right->hi - right->lo + 1))
            meta.rightRun += left->meta.rightRun;

        meta.val[0] =
            max(left->meta.val[left->meta.lazy], right->meta.val[right->meta.lazy]);
        meta.val[1] =
            max(left->meta.val[!left->meta.lazy], right->meta.val[!right->meta.lazy]);

        meta.val[actualLL] = max(meta.val[actualLL], left->meta.leftRun);
        meta.val[actualRR] = max(meta.val[actualRR], right->meta.rightRun);
        if (actualLR == actualRL)
            meta.val[actualLR] =
                max(meta.val[actualLR], left->meta.rightRun + right->meta.leftRun);
    }

    void flip(int l, int r) {
        // no cover
        if (r < lo || l > hi) return;
        // full cover
        if (l <= lo && r >= hi) {
            meta.lazy ^= 1;
        } else {
            prop();
            left->flip(l, r);
            right->flip(l, r);
            merge();
        }
    }
};

void solve(int t) {
    int n, s; cin >> n >> s;
    string config; cin >> config;
    seg tree(0, n-1, config);

    for (int i = 0; i < s; i++) {
        int l, r; cin >> l >> r;
        l--; r--;
        tree.flip(l, r);
        tree.print();
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
        solve(tt);

    return 0;
}

