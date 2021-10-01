#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n, k;
ll barn[100000];

ll cowsRequiredForMinDiff(double diff, ll a) {
    // ai(1/c - 1/c+1) = diff
    // ai(1/(c^2 + c)) = diff
    // ai = diff * c^2 + diff * c
    // 0 = diff * c^2 + diff * c - ai
    // c = (-diff + sqrt(diff * diff + 4*diff*ai)) / 2*diff
    return ceil((-diff + sqrt(diff*diff + 4*diff*a)) / (2*diff));
}

bool valid(double diff) {
    ll cows = k;
    for (int i = 0; i < n; i++) {
        ll req = cowsRequiredForMinDiff(diff, barn[i]);
        cows -= req;
        if (cows < 0) return false;
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> n >> k;
    rep(i, 0, n) cin >> barn[i];
    sort(barn, barn + n);
    reverse(barn, barn + n);

    // binary search on the increase in speed added per cow
    double lo = 1e-15, hi = 1e15, m;
    for (int i = 0; i < 250; i++) {
        m = lo + (hi - lo) / 2;
        if (valid(m)) hi = m;
        else lo = m;
    }

    long double time = 0;
    for (int i = 0; i < n; i++) {
        // assert(cowsRequiredForMinDiff(ans, barn[i]) > 0);
        time += (double)barn[i] / cowsRequiredForMinDiff(hi, barn[i]);
    }

    cout << setprecision(0) << fixed;
    cout << time << endl;

    return 0;
}
