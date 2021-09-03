#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    cout << a << ' ' << b << ' ' << c << endl;
    int count = (a >= 10) + (b >= 10) + (c >= 10);
    if ( count == 0) cout << "zilch";
    else if (count == 1) cout << "double";
    else if (count == 2) cout << "double-double";
    else cout << "triple-double";
    cout << endl << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    for (int i = 0; i < n; i++) solve();

    return 0;    
}
