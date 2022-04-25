#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <list>
#include <numeric>
#include <random>
#include <tuple>
#include <map>
#include <set>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    string one, two, three;
    cin >> one >> two >> three;

    vector<vector<vi>> dp(sz(one), vector<vi>(sz(two), vi(sz(three), -1)));

    auto go = [&](int a, int b, int c, auto &&go) -> int {
        vector<char> take;
        if (a < sz(one)) take.push_back(one[a]);
        if (b < sz(two)) take.push_back(two[b]);
        if (c < sz(three)) take.push_back(three[c]);

        if (sz(take) == 0) return 0;

        auto &ans = dp[a][b][c];
        if (ans != -1) return ans;

        ans = INT_MAX;
        for (char c : take) {
            int na = a, nb = b, nc = c;
            if (na < sz(one)) na += (c == one[na]);
            if (nb < sz(two)) nb += (c == two[nb]);
            if (nc < sz(three)) nc += (c == three[nc]);

            ans = min(ans, go(na, nb, nc, go) + 1);
        }

        return ans;
    };

    cout << go(0, 0, 0, go) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    rep(tc, 0, t) solve();

    return 0;
}

