#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll; typedef pair<int, int> pii;
typedef vector<int> vi;

int n;

void go(int val, int len) {
    if (len == n) {
        cout << val << endl;
        return;
    }

    rep(i, len == 0 ? 1 : 0, 10) {
        if ((val*10 + i) % (len + 1)) continue;
        go(val*10 + i, len + 1);
    }
}

void solve(int t) {
    cin >> n;
    go(0, 0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    rep(tt, 0, t) solve(tt);

    return 0;
}
