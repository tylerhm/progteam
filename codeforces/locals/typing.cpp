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
        string one, two; cin >> one >> two;

        if (one.length() != two.length()) {
            cout << 3 << endl;
            continue;
        }

        if (one == two) {
            cout << 1 << endl;
            continue;
        }

        bool valid = true;
        for (int i = 0; i < one.length(); i++) {
            char a = one[i];
            char b = two[i];
            
            if (b >= a - 1 && b <= a + 1 ||
                b >= a - 9 - 1 && b <= a - 9 + 1 ||
                b >= a + 9 - 1 && b <= a + 9 + 1) continue;
            
            valid = false;
            break;
        }

        cout << (valid ? 2 : 3) << endl;
    }

    return 0;    
}
