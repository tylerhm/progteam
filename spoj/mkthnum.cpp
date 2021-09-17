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
    ll l, r, m;
    stree *left = nullptr, *right = nullptr;

    stree(ll lo, ll hi) {
        l = lo;
        r = hi;
        m = lo + hi >> 1;
    }

    stree(stree *o) {
        *this = *o;
    }

    void procreate() {
        if (left) return;
        left = new stree(l, m);
        right = new stree(m+1, r);
    }

    ll query(ll lo, ll hi) {
        if (lo > r || hi < l) return 0;
        if (lo <= l && hi >= r) return val;
        procreate();
        return left->query(lo, hi) + right->query(lo, hi);
    }

    stree *update(ll idx) {
        stree *copy = new stree(this);
        if (l == r) copy->val++;
        else {
            copy->procreate();
            if (idx > m) copy->right = copy->right->update(idx);
            else copy->left = copy->left->update(idx);
            copy->val = copy->left->val + copy->right->val;
        }

        return copy;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m; cin >> n >> m;
    vector<ll> nums(n);
    for (auto &x : nums) cin >> x;

    ll upper = 1e9;
    vector<stree*> forest;

    forest.push_back(new stree(0, 2*upper));
    for (int x : nums)
        forest.push_back((*forest.back()).update(x + upper));

    rep(q, 0, m) {
        ll i, j, k; cin >> i >> j >> k;
        stree *big = forest[j];
        stree *small = forest[i-1];

        while (big->l != big->r) {
            big->procreate();
            small->procreate();
            ll leftVal = big->left->val - small->left->val;
    
            if (leftVal >= k) {
                big = big->left;
                small = small->left;
            } else {
                big = big->right;
                small = small->right;
                k -= leftVal;
            }

        }

        cout << big->l - upper << endl;
    }

    return 0;    
}
