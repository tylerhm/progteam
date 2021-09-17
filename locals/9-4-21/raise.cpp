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

    int n, r; cin >> n >> r;
    int raise = 0, doubl = 0;

    for (int i = 0; i < n; i++) {
        int money; cin >> money;
        if (money * 2 > money + r) {
            doubl++;
        } else if (money * 2 < money + r) {
            raise++;
        }
    }

    if (raise > doubl) cout << 1;
    if (doubl > raise) cout << 2;
    if (raise == doubl) cout << 0;
    cout << endl;

    return 0;    
}
