#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n, k; cin >> n >> k;
    vector<vector<char>> ans(n, vector<char>(n, '.'));

    int loc = 0;
    ans[loc][loc] = 'R';
    k--;

    while (k > 0) {
        loc += 2;
        if (loc >= n) {
            cout << -1 << nl;
            return;
        }

        ans[loc][loc] = 'R';
        k--;
    }

    for (auto v : ans) {
        for (char c : v) cout << c;
        cout << nl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc)
      solve();

    return 0;
}

