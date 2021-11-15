#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, l;
tuple<int, int, int> ans;
vector<string> ids;
vi dp;

int calcInterval(int left) {
    int furthestRight = left;
    bool valid = true;

    for (int i = 0; i < n - 1; i++) {
        // cache old maxs
        int curRight = max(left, dp[i]);

        // find first loc that we differ
        while (true) {
            if (curRight >= l) break;
            if (ids[i][curRight] != ids[i + 1][curRight]) break;
            curRight++;
        }

        furthestRight = max(curRight, furthestRight);
        if (curRight < l && ids[i][curRight] > ids[i + 1][curRight])
            valid = false;

        dp[i] = curRight;
    }

    if (!valid || furthestRight >= l) return -1;
    return furthestRight;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> n >> l;
    ids.resize(n);
    for(auto &x : ids) cin >> x;

    ans = {l, 0, l - 1};
    dp.resize(n - 1, 0);

    // for all starts
    for (int left = 0; left < l; left++) {
        // find out how far we have to move right to maintin lex order
        int right;
        if ((right = calcInterval(left)) == -1) continue;

        if (right - left + 1 < get<0>(ans))
            ans = {right - left + 1, left, right};
    }

    cout << get<1>(ans)+1 << ' ' << get<2>(ans)+1 << nl;

    return 0;
}

