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

    bool s = false, e = false;
    for (int i = 0; i < 10; i++) {
        int val; cin >> val;
        if (val == 17) s = true;
        if (val == 18) e = true;
    }

    if (s && e) {
        cout << "both";
    } else if (!s && !e) {
        cout << "none";
    } else if (s) {
        cout << 17;
    } else cout << 18;
    cout << endl;

    return 0;    
}
