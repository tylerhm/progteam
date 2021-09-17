#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
    int val; cin >> val;
    int ans = 0;
    for (int i = 0; i < val; i++) {
        ans++;
        while (ans % 3 == 0 || ans % 10 == 3) ans++;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    rep (tc, 0, t) solve(tc);

    return 0;    
}
