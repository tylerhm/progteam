#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

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

    int n; cin >> n;
    int ac, bc, cc;
    ac = bc = cc = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        ac += a; bc += b; cc += c;
        int m = min(ac, min(bc, cc));
        if (m >= 30) {
            cout << m << endl;
            ac -= m;
            bc -= m;
            cc -= m;
        } else cout << "NO" << endl;
    }

    return 0;
}

