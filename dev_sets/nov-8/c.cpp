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

    int n, c; cin >> n >> c;
    vi arr(n);
    for (auto &x : arr) cin >> x;
    sort(all(arr));

    int hi = n - 1, lo = 0;
    int ans = 0;
    while (lo <= hi) {
        if (arr[lo] + arr[hi] <= c)
            lo++;
        hi--;
        ans++;
    }

    cout << ans << endl;

    return 0;
}

