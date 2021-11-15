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

    int m, c; cin >> m >> c;

    set<int> xs, ys;
    map<int, int> monumentsX, monumentsY;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        xs.insert(x);
        ys.insert(y);
        monumentsX[x]++;
        monumentsY[y]++;
    }

    set<pii> churches;
    map<int, int> ax, ay;
    for (int i = 0; i < c; i++) {
        int x, y; cin >> x >> y;
        if (monumentsX[x] > 1 || monumentsY[y] > 1) continue;
        ax[x]++;
        ay[y]++;
        churches.emplace(x, y);
    }

    int best = 0;
    pii bestLoc = {0, 0};
    for (auto x : xs) {
        for (auto y : ys) {
            int total = 0;
            if (monumentsX[x] == 1) total += ax[x];
            if (monumentsY[y] == 1) total += ay[y];
            bool iAmActivated = (monumentsX[x] < 2 && monumentsY[y] < 2) && (monumentsX[x] == 1 || monumentsY[y] == 1);
            if (iAmActivated && churches.count({x, y})) total--;
            if (total > best) {
                best = total;
                bestLoc = {x, y};
            }
        }
    }

    cout << bestLoc.first << ' ' << bestLoc.second << endl;
    cout << best << endl;

    return 0;
}
