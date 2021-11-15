#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
    ll k; cin >> k;

    ll lo = 0, hi = 1;
    ll inc = 3;
    int shifts = 1;
    while (hi < k) {
        lo = hi;
        hi += inc;
        inc += 2;
    shifts++;
    }

    lo++;
    int row = 1, col = shifts;
    
    int val = lo;
    for (; val < k && row < shifts; val++, row++);
    for (; val < k; val++, col--);

    cout << row << ' ' << col << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    rep (tc, 0, t) solve(tc);

    return 0;    
}
