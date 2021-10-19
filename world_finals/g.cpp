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
    vector<int> price(n), perf(n), friendly(n);
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        price[i] = a;
        perf[i] = b;
        friendly[i] = c;
    }

    return 0;
}
