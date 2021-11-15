#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tt) {
    int len; cin >> len;
    string str; cin >> str;

    vi prefixA(len+1), prefixB(len+1), prefixC(len+1);
    for (int i = 0; i < len; i++) {
        prefixA[i+1] = prefixA[i];
        prefixB[i+1] = prefixB[i];
        prefixC[i+1] = prefixC[i];
        if (str[i] == 'a') prefixA[i+1]++;
        else if (str[i] == 'b') prefixB[i+1]++;
        else prefixC[i+1]++;
    }

    // we only care about strings of len 4 or less
    int ans = INT_MAX;
    for (int len = 2; len <= 7 && ans == INT_MAX; len++) {
        for (int i = 0; i < sz(str) - len + 1 && ans == INT_MAX; i++) {
            int numA = prefixA[i + len] - prefixA[i];
            int numB = prefixB[i + len] - prefixB[i];
            int numC = prefixC[i + len] - prefixC[i];
            if (numA > numB && numA > numC) ans = len;
        }
    }

    cout << (ans == INT_MAX ? -1 : ans) << nl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
        solve(tt);

    return 0;
}

