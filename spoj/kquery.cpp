#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct stree {
    ll val = 0;
    int l, r, m;
    stree *left = nullptr, *right = nullptr;

    stree(stree *o) {
        *this = *o;
    }

    stree(int lo, int hi) {
        l = lo;
        r = hi;
        m = lo + hi >> 1;
    }

    void procreate() {
        if (left) return;
        left = new stree(l, m);
        right = new stree(m+1, r);
    }

    ll query(int lo, int hi) {
        if (lo > r || hi < l) return 0;
        if (lo <= l && hi >= r) return val;
        procreate();
        return left->query(lo, hi) + right->query(lo, hi);
    }

    stree *update(int idx) {
        stree *copy = new stree(this);
        if (l == r) {
            copy->val++;
        } else {
            copy->procreate();
            if (idx > m)
                copy->right = copy->right->update(idx);
            else copy->left = copy->left->update(idx);

            copy->val = copy->left->val + copy->right->val;
        }

        return copy;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    vector<stree*> forest;
    int n; cin >> n;
    vector<ll> nums(n);
    for (auto &x : nums) cin >> x;

    ll big = 1'000'000'100;
    forest.push_back(new stree(0, big));
    for (int i = 0; i < n; i++) {
        int curVal = nums[i];
        forest.push_back(forest[i]->update(curVal));
    }

    int q; cin >> q;
    rep(ii, 0, q) {
        int i, j, k; cin >> i >> j >> k;
        cout << (forest[j]->query(k+1, big) - forest[i-1]->query(k+1, big)) << "\n";
    }

    return 0;    
}
