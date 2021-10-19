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

    int n; cin >> n;
    vector<int> palin(n);
    for (auto &x : palin) cin >> x;
    
    int lo = 0, hi = n - 1;
    int lSum = palin[lo], rSum = palin[hi];
    int removed = 0;
    while (lo < hi) {
        if (lSum == rSum) {
            lo++;
            hi--;
            lSum = palin[lo];
            rSum = palin[hi];
            continue;
        }
        removed++;

        if (lSum < rSum) {
            lo++;
            lSum += palin[lo];
            continue;
        }

        hi--;
        rSum += palin[hi];
    }

    cout << removed << endl;

    return 0;
}
