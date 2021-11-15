#include <bits/stdc++.h>
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
    cout << fixed << setprecision(9);

    int k, n; cin >> n >> k;
    vector<double> dists(n);
    for (auto &d : dists) {
        double x, y, z; cin >> x >> y >> z;
        d = sqrt(x*x + y*y + z*z);
    }

    sort(all(dists));
    cout << dists[k-1] << endl;

    return 0;
}

