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

    int d, n; cin >> d >> n;
    bool possible = d <= (n-1)*(n-1)+1;
    cout << (possible ? to_string(d * (2 * n - 2)) : "impossible") << endl;

    return 0;    
}
