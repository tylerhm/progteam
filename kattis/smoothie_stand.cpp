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

    int k, r; cin >> k >> r;
    vi ing(k);
    for (auto &x : ing)
        cin >> x;

    ll best = 0;
    for (int i = 0; i < r; i++) {
        int canMake = INT_MAX;
        for (int j = 0; j < k; j++) {
            int cost; cin >> cost;
            if (cost == 0) continue;
            canMake = min(canMake, ing[j] / cost);
        }
        ll sell; cin >> sell;
        best = max(best, canMake * sell);
    }

    cout << best << endl;

    return 0;
}

