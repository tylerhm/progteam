#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n; cin >> n;
  vector<string> board(n);
  rep(i, 0, n) cin >> board[i];

  rep(row, 0, n) {
    int rowWhite = 0, colWhite = 0;
    int rowRun = 0, colRun = 0;
    char rowRunColor = 'B', colRunColor = 'B';

    rep(col, 0, n) {
      if (board[row][col] == 'W')
        rowWhite++;
      if (board[row][col] == rowRunColor)
        rowRun++;
      else {
        rowRun = 1;
        rowRunColor = board[row][col];
      }

      if (board[col][row] == 'W')
        colWhite++;
      if (board[col][row] == colRunColor)
        colRun++;
      else {
        colRun = 1;
        colRunColor = board[col][row];
      }

      if (rowRun >= 3 || colRun >= 3) {
        cout << 0 << '\n';
        return 0;
      }
    }

    if (rowWhite != n/2 || colWhite != n/2) {
      cout << 0 << '\n';
      return 0;
    }
  }

  cout << 1 << '\n';

  return 0;  
}
