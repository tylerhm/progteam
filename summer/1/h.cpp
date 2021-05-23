#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool solve(int tt) {
    int n; cin >> n;

    vector<int> vals(n);
    for (auto &x : vals) cin >> x;

    if (n <= 4) return true;

    // third derivative at all points
    rep(i, 0, 3)
        rep(j, 0, n - 1 - i)
            vals[j] = vals[j + 1] - vals[j];
 
    rep(i, 0, n - 4) if (vals[i] != vals[i + 1]) return false;
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    rep(tt, 0, t) cout << (solve(tt) ? "YES" : "NO") << endl;

    return 0;    
}
