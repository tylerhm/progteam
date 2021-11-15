#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX_STEPS = 101;
const int MAX_ONE = 51;
const int MAX_TWO = 26;

// [distTraveled][leftOne][rightOne][leftTwo][rightTwo]
ll dp[MAX_STEPS][MAX_ONE][MAX_ONE][MAX_TWO][MAX_TWO];

void solve(int tt) {
    int garbagelol, k; cin >> garbagelol >> k;

    int maxSteps = k;
    int maxSingle = k / 6 + 1;
    int maxDouble = k / 2 + 1;

    for (int i = 0; i < maxSteps; i++)
        for (int j = 0; j < maxSingle; j++)
            for (int k = 0; k < maxSingle; k++)
                for (int l = 0; l < maxDouble; l++)
                    for (int m = 0; m < maxDouble; m++)
                        dp[i][j][k][l][m] = -1;

    auto go = [&](int dist, int singleLeft, int singleRight, int doubleLeft, int doubleRight, int curStep, auto &&go) -> ll {
        if (dist > maxSteps) return 0;
        if (singleLeft >= maxSingle) return 0;
        if (singleRight >= maxSingle) return 0;
        if (doubleLeft >= maxDouble) return 0;
        if (doubleRight >= maxDouble) return 0;

        if (dist == k) {
            if (singleLeft == singleRight && doubleLeft == doubleRight && doubleRight >= singleRight)
                return 1;
            return 0;
        }

        auto &ans = dp[dist][singleLeft][singleRight][doubleLeft][doubleRight];
        if (ans != -1) return ans;

        // only take a single step if single is < double
        ans = 0;

        // right
        if (curStep) {
            // try to take a singleRight
            ans += go(dist + 1, singleLeft, singleRight + 1, doubleLeft, doubleRight, !curStep, go);
            ans += go(dist + 2, singleLeft, singleRight, doubleLeft, doubleRight + 1, !curStep, go);
        }
        else {
            // try to take a singleRight
            ans += go(dist + 1, singleLeft + 1, singleRight, doubleLeft, doubleRight, !curStep, go);
            ans += go(dist + 2, singleLeft, singleRight, doubleLeft + 1, doubleRight, !curStep, go);
        }

        return ans;
    };

    cout << tt << ' ' << go(0, 0, 0, 0, 0, 0, go) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
        solve(tt);

    return 0;
}

