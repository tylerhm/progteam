#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tt) {
    ll n; cin >> n;
    long double lo = n * 0.95;
    long double hi = n * 1.05;

    int digitsRemoved = 0;
    while (n % 10 == 0) {
        digitsRemoved++;
        n /= 10;
    }

    ll lastdigit = n % 10;
    
    n /= 10;
    n *= 10;

    ll factor = 1;
    rep(i, 0, digitsRemoved) factor *= 10;

    if (n * factor >= lo && n * factor <= hi) {
        cout << "absurd\n";
        return;
    }

    if (lastdigit != 5) {
        n += 5;

        if (n * factor >= lo && n * factor <= hi) {
            cout << "absurd\n";
            return;
        }

        n -= 5;
    }

    if ((n * factor) + factor * 10 >= lo && (n * factor) + factor * 10 <= hi) {
        cout << "absurd\n";
        return;
    }

    cout << "not absurd\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    rep(tt, 0, t) solve(tt);

    return 0;    
}
