#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct segment {
    double a, b;
    segment(int x1, int y1, int x2, int y2) {
        double slope = (y2 - y1) / (double)(x2 - x1);
        a = slope;
        b = -slope*x1 + y1;
    }
    double solve(int x) {
        return a*x + b;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vector<pii> pts(n);
    for (auto &[x, y] : pts) cin >> x >> y;
    sort(all(pts));

    vector<vector<int>> below(n, vector<int>(n));

    // points are sorted in increasing x
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            segment s(pts[i].first, pts[i].second, pts[j].first, pts[j].second);
            // other point 
            for (int k = i + 1; k < j; k++) {
                // if it is below
                auto p = pts[k];
                double onLine = s.solve(p.first);
                int actual = p.second;
                if (actual <= onLine)
                    below[i][j]++;
            }
        }
    }

    vector<int> values(n-2);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int combined = below[i][j] + below[j][k] - below[i][k];
                if (combined < 0) combined = -combined - 1;
                values[combined]++;
            }
        }
    }

    for (int i = 0; i < n-2; i++) {
        cout << values[i] << endl;
    }

    return 0;
}
