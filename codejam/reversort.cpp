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
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    ll totalCost = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        ll cost = minIndex - i + 1;
        totalCost += cost;
        reverse(arr.begin() + i, arr.begin() + minIndex + 1);
    }
    cout << "Case #" << t << ": " << totalCost << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
        solve(tt);

    return 0;    
}
