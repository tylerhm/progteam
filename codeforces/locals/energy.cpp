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

    int first, second; cin >> first >> second;
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        int firs = min(c, 1000);
        int secon = max(0, c - 1000);

        cout << c << ' ' << firs * first + secon * second << endl;
    }

    return 0;    
}
