#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

double PI = 3.14159265358979;

double dist(double x1, double x2, double y1, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

void solve() {
    int w, bullseye, doubl, single; cin >> w >> bullseye >> doubl >> single;
    double arclen = PI * 2 / w;

    ll score = 0;
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        double x, y; cin >> x >> y;

        // determine which wedge it falls in
        double angle = atan2(y, x);
        if (angle < 0) angle += PI * 2;

        // determine which radius it falls in
        int mult;
        double d = dist(x, 0, y, 0);
        if (d < bullseye) mult = 0;
        else if (d < doubl) mult = 2;
        else if (d < single) mult = 1;
        else continue;

        if (mult == 0) {
            score += 50;
            continue;
        }

        int wedge = angle / arclen;
        wedge++;
        score += wedge * mult;
    }

    cout << score << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    for (int i = 0; i < n; i++) solve();

    return 0;    
}
