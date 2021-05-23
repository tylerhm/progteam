#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct minMax {
    int mi, ma;
    minMax() : mi(INT_MAX), ma(INT_MIN) {}
    void insert(int val) {
        mi = min(mi, val);
        ma = max(ma, val);
    }
};

struct statement {
    int t, j, i;
    statement() : t(0), j(0), i(0) {}
    statement(int t, int j, int i) : t(t), j(j), i(i) {}
};

void solve(int tt) {
    int n, m; cin >> n >> m;
    map<int, minMax> people;
    vector<statement> statements(m);
    int t, j, i;
    rep(k, 0, m) {
        cin >> t >> j >> i;
        j--; t--;
        people[j].insert(t);
        statements[k] = {t, j, i};
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
