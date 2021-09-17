#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int sugar_buy = 80;
    int d, x, s; cin >> d >> x >> s;

    int miPl = INT_MAX, miPs = INT_MAX;
    int sugarLeft = 0;
    ll cost = 0;
    for (int i = 0; i < d; i++) {
        int c, pl, ps; cin >> c >> pl >> ps;
        miPl = min(miPl, pl);
        miPs = min(miPs, ps);

        int sugarNeeded = c*s - sugarLeft;
        int bagsBuy = ceil((double)sugarNeeded / sugar_buy);
        cost += c*x*miPl + bagsBuy*miPs;

        sugarLeft += bagsBuy * sugar_buy;
        sugarLeft -= c*s;
    }

    cout << cost << endl;

    return 0;    
}
