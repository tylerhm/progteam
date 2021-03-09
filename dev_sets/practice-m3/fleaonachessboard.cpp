#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int square[1010][1010];

bool solve(int ver) {
    ll s, x, y, dx, dy; cin >> s >> x >> y >> dx >> dy;
    ll startx = x, starty = y;
    if (s == 0 && x == 0 && y == 0 && dx == 0 && dy == 0) return false;

    ll jumps = 0;
    while (true) {

        if (square[x%s][y%s] == ver) {
            cout << "The flea cannot escape from black squares.\n";
            return true;
        }

        square[x%s][y%s] = ver;

        bool on_white = (((x / s)&1)^((y / s)&1)) && (x%s) && (y%s);

        if (on_white) {
            cout << "After " << jumps << " jumps the flea lands at (" << (startx+dx*jumps) << ", " << (starty+dy*jumps) << ").\n";
            return true;
        }

        jumps++;

        x += dx;
        y += dy;
    }


    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int ver = 1;
    while (solve(ver++));

    return 0;    
}
