#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define PI 3.14159265358979
#define EPSILON 1e-9

bool eps_equal(double a, double b) {
    return abs(a - b) < EPSILON || abs(a - b) < EPSILON * max(a, b);
}

void solve() {
    double s, r; cin >> s >> r;
    
    // circle in square
    if (r < s / 2) {
        cout << PI * r * r << endl;
        return;
    }

    // square in circle
    if (s / sqrt(2) < r || eps_equal(s / sqrt(2), r)) {
        cout << s * s << endl;
        return;
    }

    // get size of triangle above arc
    double s1 = s / 2;
    double s3 = r;
    // s1^2 + s2^2 = s3^2
    double s2 = sqrt(s3*s3 - s1*s1);
    double A = s1 * s2 / 2;

    // get area of arc in middle
    double y = s / 2;
    double x = sqrt(r*r - (s*s/4));

    double theta = atan2(y, x) - atan2(x, y);
    double ratio = theta / (2 * PI);
    double B = ratio * PI * r * r;

    cout << 8 * A + 4 * B << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cout << fixed << setprecision(2);

    int n; cin >> n;
    for (int i = 0; i < n; i++) solve();

    return 0;    
}
