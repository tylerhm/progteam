#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct max_seg {
  int l, r, m, lazy, val;
  max_seg *left, *right;

  max_seg(int lo, int hi) {
    l = lo; r = hi;
    m = (l + r) >> 1;
    lazy = 0;
    val = 0;

    if (l != r) {
      left = new max_seg(l, m);
      right = new max_seg(m + 1, r);
    }
  }

  int get() {
    return val + lazy;
  }

  void prop() {
    val += lazy;
    left->lazy += lazy;
    right->lazy += lazy;
    lazy = 0;
  }

  void update(int lo, int hi, int dval) {
    if (lo > r || hi < l) return;
    if (lo <= l && hi >= r) {
      lazy += dval;
      return;
    }

    prop();
    left->update(lo, hi, dval);
    right->update(lo, hi, dval);
    val = max(left->get(), right->get());
  }

  int query(int lo, int hi) {
    if (lo > r || hi < l) return INT_MIN;
    if (lo <= l && hi >= r) return get();

    prop();
    return max(left->query(lo, hi), right->query(lo, hi));
  }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;

    vector<pii> intervals(n);
    for (auto &[start, end] : intervals)
      cin >> start >> end;

    vector<tuple<int, int, int>> pois;

    return 0;
}

