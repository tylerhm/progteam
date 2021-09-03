#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<bool> rows, cols;
vector<vector<bool>> board;
int w;

void punch(int row, int col) {
    rows[row] = false;
    cols[col] = false;
    
    for (int r = 0; r < w; r++)
        if (!rows[r])
            board[r][col] = false;
    for (int c = 0; c < w; c++)
        if (!cols[c])
            board[row][c] = false;
}

void solve(int t) {
    cout << "Strategy #" << t << ": ";

    int m; cin >> w >> m;
    rows = vector<bool>(w, true);
    cols = vector<bool>(w, true);
    board = vector<vector<bool>>(w, vector<bool>(w, true));

    int invalid = 0;
    for (int i = 0; i < m; i++) {
        int r, c; cin >> r >> c; r--; c--;
        if (!board[r][c]) invalid++;
        else punch(r, c);
    }

    cout << invalid << endl << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    for (int i = 0; i < n; i++) solve(i + 1);

    return 0;    
}
