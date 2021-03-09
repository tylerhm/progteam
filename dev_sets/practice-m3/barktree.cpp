#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<bool> visited;
queue<pii> toys;
vector<pii> trees;

double pairDist(pii one, pii two) {
    ll a = one.first-two.first;
    ll b = one.second-two.second;
    return sqrt(a*a + b*b);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cout << setprecision(2);
    cout << fixed;

    cin >> n >> m;
    toys = queue<pii>();
    trees = vector<pii>(m);
    visited = vector<bool>(n, false);

    rep(i, 0, n) {
        int x, y; cin >> x >> y;
        toys.push(make_pair(x, y));
    }
    rep(i, 0, m) {
        int x, y; cin >> x >> y;
        trees[i] = make_pair(x, y);
    }

    // special case one and two
    if (toys.size() == 0) {
        cout << 0.00;
        return 0;
    }
    if (toys.size() == 1) {
        pii one {0, 0};
        pii two = toys.front(); toys.pop();
        cout << pairDist(one, two);
        return 0;
    }

    pii a {0, 0};
    pii b = toys.front(); toys.pop();
    pii c;

    while (!toys.empty()) {
        c = toys.front(); toys.pop();

        pii ab, bc;
        ab = make_pair(b.first - a.first, b.second - a.second);
        bc = make_pair(b.first - c.first, b.second - c.second);

        double angba = atan2(ab.second, ab.first);
        double angbc = atan2(bc.second, bc.first);
        double res = angba - angbc;
        double deg = res * 180 / M_PI;
        cout << deg << "\n";

        a = b;
        b = c;
    }

    return 0;    
}
