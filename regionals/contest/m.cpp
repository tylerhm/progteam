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

    int n, k; cin >> n >> k;

    int solidSum = 0;
    rep(i, 0, k) {
        int val; cin >> val;
        solidSum += val;
    }

    // try max
    int maxSum = solidSum + 3 * (n - k);
    int minSum = solidSum - 3 * (n - k);

    cout << (minSum / (double)n) << ' ' << (maxSum / (double)n) << "\n";

    return 0;
}
