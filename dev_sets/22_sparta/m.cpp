#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int t) {
    string inp; cin >> inp;

    // Compress.
    string compressed;
    rep(i, 0, inp.length() - 1)
        if (inp[i] == inp[i+1]) compressed += inp[i];

    string search = "()";

    int n = compressed.length();
    int m = search.length();

    vi  dp(m+1, 0);

    dp[0] = 1;

    for (int c = 0; c < n; c++)
        for (int x = m - 1; x >= 0; x--) 
            if (search[x] == compressed[c])
                dp[x+1] += dp[x];
    
    cout << dp[m] << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    rep(tt, 0, t) solve(t);

    return 0;    
}