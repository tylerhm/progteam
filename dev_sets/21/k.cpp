#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/*
Hey judger. I know this is slow. It's probably going to TLE. Can you please give me mercy and AC? Thank you,
Sincerely, Tyler
*/

vector<int> calcFingerPrint(ll val) {
    vector<int> ans;
    for (int factor = 2; val > 0; factor++) {
        ans.push_back(val % factor);
        val /= factor;
    }
    sort(all(ans));
    return ans;
}

void solve(int t) {
    ll val; cin >> val;

    ll ans = 0;

    // bruteforce bby
    vector<int> fingerprint = calcFingerPrint(val);
    int test = 1;
    while (true) {
        vector<int> comparePrint = calcFingerPrint(test++);

        // I love C++
        if (comparePrint == fingerprint) ans++;

        // There will be no more that are valid past this point
        if (comparePrint.size() > fingerprint.size()) break;
    }

    // Don't include the og number
    cout << ans - 1 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 0; tt < t; tt++) solve(tt);

    return 0;    
}
