#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
ll MAX_PLACE = 1000000;

vector<vector<int>> board;
vector<bool> used;
vector<ll> rowSum, colSum;
vector<vector<bool>> rowCont, colCont;

bool valid(int row, int col, int val) {
    if (used[val]) return false;
    if (row == n - 1) {
        double sum = colSum[col] + val;
        double av = sum / n;
        int av2 = sum / n;
        if (av != av2) return false;
        if (!colCont[col][av2]) return false;
    }
    if (col == n - 1) {
        double sum = rowSum[row] + val;
        double av = sum / n;
        int av2 = sum / n;
        if (av != av2) return false;
        if (!rowCont[row][av2]) return false;
    }
    return true;
}

bool backtrack(int row, int col) {
    if (col == n) return backtrack(row + 1, 0);
    if (row == n) return true;

    // loop up till we can place
    for (int i = 1; i < MAX_PLACE; i++) {
        if (valid(row, col, i)) {
            board[row][col] = i;
            used[i] = true;
            rowCont[row][i] = true;
            colCont[col][i] = true;
            rowSum[row] += i;
            colSum[col] += i;

            if (backtrack(row, col + 1))
                return true;

            used[i] = false;
            rowCont[row][i] = false;
            colCont[col][i] = false;
            rowSum[row] -= i;
            colSum[col] -= i;
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> n;
    if (n == 1) {
        cout << 133769420 << "\n";
        return 0;
    }
    if (n == 2) {
        cout << -1 << "\n";
        return 0;
    }
    board = vector<vector<int>>(n, vector<int>(n));
    used = vector<bool>(MAX_PLACE);
    rowSum = vector<ll>(n);
    colSum = vector<ll>(n);
    rowCont = vector<vector<bool>>(n, vector<bool>(MAX_PLACE));
    colCont = vector<vector<bool>>(n, vector<bool>(MAX_PLACE));
    if (backtrack(0, 0)) {
        for (auto v : board) {
            for (int i : v) cout << i << ' ';
            cout << "\n";
        }
    } else cout << -1 << "\n";

    return 0;
}
