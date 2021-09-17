#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, k;
int times[110'000];

bool test(ll d) {
    ll lo, hi;
    int cnt = 0;

    lo = times[0];
    for (int i = 0; i < n; i++) {
        if (cnt == k) return false;
        if (hi - lo > d) {
            if (++cnt > n) return false;
            lo = times[i];
        }

        hi = times[i];
    }

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> n >> k;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        times[i] = val;
    }
    sort(times, times + n);

    ll lo = 0, hi = 1e9, mid;
    ll ans;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (test(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    cout << ans << endl;

    return 0;    
}
