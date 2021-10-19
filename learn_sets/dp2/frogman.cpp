#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int ox[1010], nit[1010], weight[1010];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t, a; cin >> t >> a;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ox[i] >> nit[i] >> weight[i];

    vector<vector<vi>> dp(t+1, vector<vi>(a+1, vector<int>(1010, -1)));
    auto go = [&](int idx, int curOx, int curNit, auto &&go) -> int {
        if (curOx >= t && curNit >= a) return 0;
        if (idx == n) return 1e9;
        auto &ans = dp[curOx][curNit][idx];
        if (ans != -1) return ans;

        ans = 1e9;
        ans = min(ans, go(idx + 1, min(curOx + ox[idx], t), min(curNit + nit[idx], a), go) + weight[idx]);
        ans = min(ans, go(idx + 1, curOx, curNit, go));

        return ans;
    };
    cout << go(0, 0, 0, go) << endl;

    return 0;
}
