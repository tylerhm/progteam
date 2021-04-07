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

    string inp; cin >> inp;
    char lastchar = ' ';
    ll longest = 0, current = 0;
    rep(i, 0, inp.length()) {
        if (inp[i] == lastchar) current++;
        else {
            longest = max(longest, current);
            current = 1;
        }
        lastchar = inp[i];
    }
    longest = max(longest, current);

    cout << longest << "\n";

    return 0;    
}
