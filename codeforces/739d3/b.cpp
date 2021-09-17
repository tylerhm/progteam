#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
    int a, b, c;
    cin >> a >> b >> c;

    int n = 2 * abs(a - b);
    if (a > n || b > n || c > n) {
        cout << -1 << endl;
        return;
    }

    if (c <= n / 2) {
        cout << (n / 2) + c << endl;
        return;
    }

    cout << abs(c - n / 2) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    rep (tc, 0, t) solve(tc);

    return 0;    
}
