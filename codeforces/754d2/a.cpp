#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tt) {
    int a, b, c; cin >> a >> b >> c;

    int minVar = INT_MAX;
    while (true) {
        if (2*b < a + c) {
            b++; a--;
        } else if (2*b > a + c) {
            b--; a++;
        }
        if (abs(a + c - 2*b) < minVar) {
            minVar = abs(a + c - 2*b);
        } else break;
    }

    cout << minVar << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }

    return 0;
}

