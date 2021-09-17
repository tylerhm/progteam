#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

double dist[15][15];
bool blocked[15][15];
bool visited[15];
int r;

double minDist;

double pDist(pii a, pii b) {
    ll dx = abs(a.first - b.first);
    ll dy = abs(a.second - b.second);
    return sqrt(dx*dx + dy*dy);
}

void go(int u, int found, double d) {
    if (found == r) {
        minDist = min(minDist, d);
        return;
    }

    rep(v, 1, r+1) {
        if (!visited[v] && !blocked[u][v]) {
            visited[v] = true;
            go(v, found + 1, d + dist[u][v]);
            visited[v] = false;
        }
    }
}

void solve(int t) {
    cout << "Vacation #" << t << ":" << endl;

    int b; cin >> r >> b;
    vector<pii> rides(r);
    for (auto &[x, y] : rides)
        cin >> x >> y;

    rides.insert(rides.begin(), {0, 0});

    rep(i,0,sz(rides))
        rep(j,0,sz(rides))
            if (i != j)
                dist[i][j] = pDist(rides[i], rides[j]);
    
    rep(i,0,15)
        rep(j,0,15)
            blocked[i][j] = false;
    rep(i,0,b) {
        int u, v; cin >> u >> v;
        blocked[u][v] = true;
        blocked[v][u] = true;
    }

    rep(i,0,sz(rides)) visited[i] = false;
    visited[0] = true;

    minDist = DBL_MAX;
    go(0, 0, 0.0);

    if (minDist == DBL_MAX) {
        cout << "Jimmy should plan this vacation a different day." << endl;
    } else {
        minDist += 120 * r;
        cout << "Jimmy can finish all of the rides in " << minDist << " seconds." << endl;
    }

    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cout << fixed << setprecision(3);

    int t; cin >> t;
    rep(tt, 0, t) solve(tt+1);

    return 0;    
}
