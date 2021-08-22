#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int er, ec;
vector<int> lens;
set<pii> visited;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        lens.resize(l);
        for (auto &x : lens) cin >> x;

        int sr, sc; cin >> sr >> sc;
        cin >> er >> ec;

        visited.clear();
        visited.insert({sr, sc});

        queue<pair<pii, int>> q;
        q.push({{sr, sc}, 0});

        int ans;
        while (true) {
            auto cur = q.front(); q.pop();
            int dist = cur.second;

            auto loc = cur.first;
            int row = loc.first;
            int col = loc.second;

            if (row == er && col == ec) {
                ans = dist;
                break;
            }

            if (row > 1) {
                int nrow = row - 1;
                int ncol = min(col, lens[nrow - 1]);
                if (visited.insert({nrow, ncol}).second)
                    q.push({{nrow, ncol}, dist + 1});
            }

            if (row < lens.size()) {
                int nrow = row + 1;
                int ncol = min(col, lens[nrow - 1]);
                if (visited.insert({nrow, ncol}).second)
                    q.push({{nrow, ncol}, dist + 1});
            }

            if (col > 0) {
                if (visited.insert({row, col - 1}).second)
                    q.push({{row, col - 1}, dist + 1});
            } else {
                if (row == 1) continue;

                int nrow = row - 1;
                int ncol = lens[nrow - 1];
                if (visited.insert({nrow, ncol - 1}).second)
                    q.push({{nrow, ncol - 1}, dist + 1});
            }

            if (col < lens[row - 1]) {
                if (visited.insert({row, col + 1}).second)
                    q.push({{row, col + 1}, dist + 1});
            } else {
                if (row == lens.size()) continue;

                int nrow = row + 1;
                int ncol = 0;
                if (visited.insert({nrow, ncol - 1}).second)
                    q.push({{nrow, ncol - 1}, dist + 1});
            }
        }

        cout << ans << endl;
    }

    return 0;    
}
