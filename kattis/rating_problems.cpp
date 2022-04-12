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

    int n, k; cin >> n >> k;
    int curSum = 0;
    for (int i = 0; i < k; i++) {
        int val; cin >> val;
        curSum += val;
    }

    int mx = curSum + (n - k) * 3;
    int mn = curSum - (n - k) * 3;

    cout << ((double)mn / n) << ' ' << ((double)mx / n) << endl;

    return 0;
}

