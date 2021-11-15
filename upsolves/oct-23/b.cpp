#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, w, h; cin >> n >> w >> h;
    vi widths(n), heights(n);
    vector<vi> dp(n, vi(w+1, -1));

    int mx = 0;
    int widthSum = 0;
    for (int i = 0; i < n; i++) {
        cin >> widths[i] >> heights[i];
        widthSum += widths[i];
        mx = max(mx, heights[i]);
    }

    if (widthSum > 2*w) {
        cout << "impossible" << endl;
        return 0;
    }

    auto go = [&](int idx, int filledBot, int filledTop, auto &&go) -> bool {
        if (idx == n) return true;
        auto &ans = dp[idx][filledBot];
        if (ans != -1) return ans;

        bool valid = false;
        if (w - filledBot >= widths[idx] && heights[idx] <= mx)
            valid |= go(idx + 1, filledBot + widths[idx], filledTop, go);
        if (valid) return ans = valid;
        if (w - filledTop >= widths[idx] && heights[idx] <= h - mx)
            valid |= go(idx + 1, filledBot, filledTop + widths[idx], go);
        return ans = valid;
    };

    if (mx <= h && go(0, 0, 0, go)) {
        if (mx == h) cout << -1 << endl;
        else cout << mx << endl;
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}

