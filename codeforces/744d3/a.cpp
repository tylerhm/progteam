#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    string s; cin >> s;
    int ac, bc, cc;
    ac = bc = cc = 0;
    for (char c : s) {
        if (c == 'A') ac++;
        if (c == 'B') bc++;
        if (c == 'C') cc++;
    }

    if (bc == ac + cc) cout << "YES";
    else cout << "NO";
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    rep(tt, 0, t) solve();

    return 0;
}
