#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct stree {
    int l, r, m, val = 0;
    stree *left, *right;

    stree(int lo, int hi) {
        l = lo;
        r = hi;
        m = l + r >> 1;

        if (l != r) {
            left = new stree(l, m);
            right = new stree(m + 1, r);
        }
    }

    void set(int idx, int nval) {
        if (l == r) val = nval;
        else {
            if (idx <= m) left->set(idx, nval);
            else right->set(idx, nval);
            val = left->val + right->val;
        }
    }

    int query(int lo, int hi) {
        if (lo > r || hi < l) return 0;
        if (lo <= l && hi >= r) return val;
        return left->query(lo, hi) + right->query(lo, hi);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vector<int> prof(n), par(n, -1);
    for (auto &x : prof) cin >> x;
    for (int i = 1; i < n; i++) cin >> par[i], par[i]--;

    vector<pii> revOrder;
    for (int i = 0; i < n; i++)
        revOrder.emplace_back(-prof[i], i);
    sort(all(revOrder));

    vector<vi> adjList(n);
    int root;
    for (int i = 0; i < n; i++) {
        if (par[i] == -1) {
            root = i;
            continue;
        }
        adjList[par[i]].push_back(i);
    }

    vector<int> pre(n), post(n);
    int curPre = -1, curPost = -1;
    function<void(int)> dfs = [&](int loc) {
        curPre++, curPost++;
        pre[loc] = curPre;
        for (int c : adjList[loc])
            dfs(c);
        post[loc] = curPost;
    };

    vector<pii> ans;

    stree seg(0, n);
    for (int i = 0; i < n; i++) {
        int nextInsertion = revOrder[i].second;
        int greaterThan = seg.query(pre[nextInsertion], post[nextInsertion]);
        ans.emplace_back(nextInsertion, greaterThan);
        seg.set(nextInsertion, 1);
    }

    sort(all(ans));

    for (auto i : ans) cout << i.second  << endl;

    return 0;
}
