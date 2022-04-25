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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    double a, b;
    while (cin >> a >> b) {
        int n; cin >> n;
        vector<pair<double, double>> intervals(n);
        for (auto &[x, y] : intervals) cin >> x >> y;

        sort(all(intervals));

        vector<double> ends;
        for (auto [_, y] : intervals)
            ends.push_back(y);
        sort(all(ends));
        map<double, int> endComp;
        for (auto e : ends)
            endComp[e] = sz(endComp);

        // [idx][curEndComp]
        vector<vi> dp(n+5, vi(sz(endComp)+5, -1));

        auto go = [&](int idx, int curEndComp, auto &&go) -> int {
            if (idx >= n) return 0;

            auto &ans = dp[idx][curEndComp];
            if (ans != -1) return ans;

            int take =
        };
    }

    return 0;
}

