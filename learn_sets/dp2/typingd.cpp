#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dist(char a, char b) {

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;

    int sz1, sz2;
    vector<vi> dp;
    auto go = [&](int idx1, int idx2, auto &&go) {
        if (idx1 >= sz1 && idx2 >= sz2) return 0;

        auto &ans = dp[idx1][idx2];
    };

    for (int i = 0; i < n; i++) {
        string one, two; cin >> one >> two;
        sz1 = sz(one), sz2 = sz(two);
        dp = vector<vi>(sz1+1, vi(sz2+1, -1));
        cout << go(0, 0, go) << endl;
    }

    return 0;
}
