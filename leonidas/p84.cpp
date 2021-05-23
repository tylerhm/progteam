#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<string> grid;
map<pair<int, int>, bool> visited;

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};

bool valid(pair<int, int> p) {
    return
        p.first >= 0 && p.first < n &&
        p.second >= 0 && p.second < m &&
        grid[p.first][p.second] != '#';
}

void race(queue<pair<pair<int, int>, int>> q, pair<int, int> e, int &shortestDist) {
    if (q.empty()) return;
    auto p = q.front(); q.pop();
    
    if (p.first == e) {
        shortestDist = min(shortestDist, p.second);
        return;
    }

    pair<int, int> next;
    rep(i, 0, 4) {
        if (!valid({p.first.first + dy[i], p.first.second + dx[i]})) continue;

        int dist = 1;
        while (valid({p.first.first + dy[i] * dist, p.first.second + dx[i] * dist})) dist++;
        dist--;
        dist = dist - dist / 2;

        next = {p.first.first + dy[i] * dist, p.first.second + dx[i] * dist};
        if (visited[next]) continue;
        visited[next] = true;
        q.push({next, p.second + 1});
    }
    race(q, e, shortestDist);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> n >> m;
    grid = vector<string>(n);
    for (auto &x : grid) cin >> x;

    pair<int, int> s, e;
    rep(y, 0, n)
        rep(x, 0, m)
            if (grid[y][x] == 'S') s = {y, x};
            else if (grid[y][x] == 'T') e = {y, x};

    int shortestDist = INT_MAX;
    visited.clear();

    queue<pair<pair<int, int>, int>> q;
    q.push({s, 0});
    race(q, e, shortestDist);

    cout << (shortestDist != INT_MAX ? shortestDist : -1) << endl;
    
    return 0;    
}
