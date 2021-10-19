#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tt) {
    ll num; cin >> num;

    // find the number of removals in order to get either
    // 00
    // 25
    // 50
    // 75 
    // on the right

    bool foundZero = false;
    int secondZero = INT_MAX, secondFive = INT_MAX;
    bool foundFive = false;
    int secondTwo = INT_MAX, secondSeven = INT_MAX;

    int idx = 0;
    while (num > 0) {
        int digit = num % 10;
        num /= 10;

        if (digit == 0) {
            if (foundZero && secondZero == INT_MAX) secondZero = idx;
            foundZero = true;
        }

        if (digit == 2 && foundFive && secondTwo == INT_MAX) secondTwo = idx;

        if (digit == 5) {
            if (foundZero && secondFive == INT_MAX) secondFive = idx;
            foundFive = true;
        }

        if (digit == 7 && foundFive && secondSeven == INT_MAX) secondSeven = idx;

        idx++;
    }

    // removal dists are
    int d1 = secondZero - 1;
    int d2 = secondTwo - 1;
    int d3 = secondFive - 1;
    int d4 = secondSeven - 1;

    cout << min(d1, min(d2, min(d3, d4))) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 0; tt < t; tt++) solve(tt);

    return 0;
}
