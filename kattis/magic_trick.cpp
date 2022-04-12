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

    string inp; cin >> inp;
    vi cnt(26);
    for (char c : inp)
        if (++cnt[c - '0'] > 1) {
            cout << 0 << endl;
            return 0;
        }

    cout << 1 << endl;

    return 0;
}

