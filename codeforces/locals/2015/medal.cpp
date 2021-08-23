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
    for (int i = 0; i < n; i++) {
        int ug, us, ub; cin >> ug >> us >> ub;
        int rg, rs, rb; cin >> rg >> rs >> rb;
        cout << ug << ' ' << us << ' ' << ub << ' ';
        cout << rg << ' ' << rs << ' ' << rb << endl;

        int ut = ug + us + ub;
        int rt = rg + rs + rb;

        bool count = ut > rt;

        bool color = false;
        if (ug > rg) color = true;
        else if (ug == rg) {
            if (us > rs) color = true;
            else if (us == rs) {
                if (ub > rb) color = true;
            }
        }

        if (color && count) cout << "both";
        else {
            if (color) cout << "color";
            else if (count) cout << "count";
            else cout << "none";
        }
        cout << endl << endl;
    }

    return 0;    
}
