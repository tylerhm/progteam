#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int r, c, f;
vector<vector<bool>> subs;
vector<vector<ll>> dist;
vector<vector<ll>> steps;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve(int row, int col, int curDist, int curSteps) {
    for (int i = 0; i < 4; i++) {
        // get the location that we are moving to
        int nrow = row + dy[i];
        int ncol = col + dx[i];

        // if it is out of bounds stop
        if (nrow < 0 || nrow >= r || ncol < 0 || ncol >= c) continue;

        int newSteps = curSteps + 1;
        if (subs[nrow][ncol]) newSteps = 0;
        int newDist = curDist + 1;

        // we should continue going if
        // 1. we got a better step count then before
        // 2. we got a lower dist than before
        if (!(newSteps < steps[nrow][ncol] || newDist < dist[nrow][ncol])) continue;
        
        dist[nrow][ncol] = newDist;
        steps[nrow][ncol] = newSteps;

        if (newSteps == f) continue;

        solve(nrow, ncol, newDist, newSteps);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int s; cin >> r >> c >> f >> s;
    subs = vector<vector<bool>>(r, vector<bool>(c, false));
    dist = vector<vector<ll>>(r, vector<ll>(c, INT_MAX));
    steps = vector<vector<ll>>(r, vector<ll>(c, INT_MAX));

    rep(i,0,s) {
        int r, c; cin >> r >> c;
        r--; c--;

       subs[r][c] = true; 
    }

    solve(0, 0, 0, 0);
    cout << dist[r-1][c-1] << endl;

    return 0;    
}
