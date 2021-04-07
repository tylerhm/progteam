#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int t) {
    int n; cin >> n;
    map<int, int> categoryCount;
    rep(i, 0, n) {
        int c; cin >> c;
        categoryCount[c]++;
    }

    vector<int> taken;
    int minCount = n + 1;
    for (int i = 1; i <= n; i++) {
        if (categoryCount[i]) {
            taken.push_back(categoryCount[i]);
            minCount = min(minCount, categoryCount[i]);
        }
    }

    int minCountAgain = n + 1;
    for (int i = 1; i <= minCount + 1; i++) {
        int res = 0;
        for (int c : taken) {
            int div = c / i;
            int rem = c % i;
            if (div + rem >= i - 1 || rem == 0)
                res += div + (rem == 0 ? 0 : 1);
            else {
                res = INT_MIN;
                break;
            }
        }
        if (res != INT_MIN) minCountAgain = min(minCountAgain, res);
    }
    cout << minCountAgain << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 0; tt < t; tt++) solve(t);

    return 0;    
}
