#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define PI 3.1415926535897932384

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cout << fixed << setprecision(9);

    double r, s, h, m, d; cin >> r >> s >> h >> m >> d;

    double bigVol = (PI / 3) * h * (s * s + r * r + s * r);

    double newS = r + ((s - r) / (h / d));
    double smallVol = (PI / 3) * d * (newS * newS + r * r + newS * r);

    double difference = bigVol - smallVol;
    double speed = difference / m;

    double remaining = smallVol / speed;

    cout << remaining << endl;

    return 0;    
}
