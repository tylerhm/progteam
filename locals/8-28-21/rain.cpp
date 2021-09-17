#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define PI 3.14159265358979

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cout << fixed << setprecision(2);

    double s, r; cin >> s >> r;

    // circle in square
    if (s / 2 > r) {
        cout << PI * r * r << endl;
    }
    
    // square in circle
    // diag of square = s * sqrt(2)
    else if (s * sqrt(2) <= r * 2) {
        cout << s * s << endl;
    }

    // math
    else {
        double height = s/2;
        double x1 = sqrt(r * r - (s * s) / 4);
        double y1 = s/2;

        double tri1 = height * x1 / 2;
        double B = tri1 * 8;

        double theta = atan2(y1, x1) - atan2(x1, y1);
        double ratio = theta / (2 * PI);

        double tri2 = PI * r * r * ratio;
        double C = tri2 * 4;

        cout << B + C << endl;
    }

    return 0;    
}
