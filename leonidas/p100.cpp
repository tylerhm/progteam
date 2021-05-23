#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool visited[8][8];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};

struct pos {
    int y, x;
    pos(int y, int x) : y(y), x(x) {}
    string conv() {
        string ret = "";
        ret += char('a' + x);
        ret += char('8' - y);
        return ret;
    }
    bool operator==(const pos o) const {
        return o.y == y && o.x == x;
    }
};

pos BAD = pos(-1, -1);

bool validMove(int y, int x) {
    return
        y >= 0 && y < 8 &&
        x >= 0 && x < 8 &&
        !visited[y][x];
}

queue<pos> ans;

bool backtrack(queue<pos> path) {
    auto point = path.front();
    if (point.y == 0 && point.x == 7) {
        ans = path;
        return true;
    }
    rep(i, 0, 4) {
        for (int j = 1;; j++) {
            int ny = point.y + dy[i] * j;
            int nx = point.x + dx[i] * j;
            if (!validMove(ny, nx)) break;

            path.emplace(
                ny,
                nx
            );
            visited[ny][nx] = true;
            if (backtrack(path)) return true;
            path.pop();
            visited[ny][nx] = false;
        }
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;

    queue<pos> path;
    path.emplace(7, 0);
    backtrack(path);
    while (!ans.empty()) {
        cout << ans.front().conv() << ' ';
        ans.pop();
    }
    cout << endl;

    return 0;    
}
