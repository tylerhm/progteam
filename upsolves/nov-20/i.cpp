#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

double circles[501][501];
int version[501][501];
int version2[501][501];

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
};

typedef Point<double> P;
double segDist(P& s, P& e, P& p) {
    if (s==e) return (p-s).dist();
    auto d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));
    return ((p-s)*d-(e-s)*t).dist()/d;
}

int DX[] = {1, 0, 1, 0}, DY[] = {0, 1, 0, -1};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    __builtin_ia32_ldmxcsr(40896);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        double r; cin >> r;
        circles[x][y] = r; // no circles overlap
    }

    int k; cin >> k;
    int x1, y1, x2, y2;
    for (int i = 1; i <= k; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        int cnt = 0;
        if (x1 == x2) { // vert
            for (int j = min(y1, y2); j <= max(y1, y2); j++)
                if (circles[x1][j]) cnt++;
        } else if (y1 == y2) { // hori
            for (int j = min(x1, x2); j <= max(x1, x2); j++)
                if (circles[j][y1]) cnt++;
        } else {
            P s(x1, y1), e(x2, y2);
            if (e<s) swap(s, e);
            queue<pii> bfs;

            int sx = s.x, sy = s.y;
            bfs.emplace(sx, sy);
            version[sx][sy] = i;

            // either go down right or up right
            double m = (e.y - s.y) / (e.x - s.x);
            int start = m > 0 ? 0 : 2;
            int end = m > 0 ? 1 : 3;

            while (!bfs.empty()) {
                auto [x, y] = bfs.front();
                bfs.pop();
                P p(x, y);
                if (version2[x][y] != i && circles[x][y] && circles[x][y] > segDist(s, e, p)) {
                    version2[x][y] = i;
                    cnt++;
                }
                for (int d = start; d <= end; d++) {
                    int nx = x + DX[d];
                    int ny = y + DY[d];
                    P p(nx, ny);
                    if (version[nx][ny] != i && segDist(s, e, p) < 1) {
                        bfs.emplace(nx, ny);
                        version[nx][ny] = i;
                    }
                }
            }
        }

        cout << cnt << nl;
    }

    return 0;
}
