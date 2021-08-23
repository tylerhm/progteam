#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define SUGAR_BUY 80

void solve() {
    int d, x, s; cin >> d >> x >> s;

    int sCnt = 0;
    int minLp = INT_MAX, minSp = INT_MAX;
    int cost = 0;
    for (int i = 0; i < d; i++) {
        int c, lp, sp; cin >> c >> lp >> sp;
        minLp = min(minLp, lp);
        minSp = min(minSp, sp);
        int sugar = c * s;
        int neededSugar = sugar - sCnt;

        int bagsToBuy = ceil((double)neededSugar / SUGAR_BUY);
        int lemonsToBuy = c * x;

        cost += lemonsToBuy * minLp;
        cost += bagsToBuy * minSp;

        sCnt -= sugar;
        sCnt += bagsToBuy * SUGAR_BUY;
    }

    cout << cost << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    for (int i = 0; i < n; i++) solve();

    return 0;    
}
