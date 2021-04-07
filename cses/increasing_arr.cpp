#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n; cin >> n;
    ll lastVal = 0;
    ll added = 0;
    rep(i, 0, n) {
        ll val; cin >> val;
        if (val < lastVal) {
            added += lastVal - val;
            val = lastVal;
        }
        lastVal = val;
    }

    cout << added << "\n";

    return 0;    
}
