#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<vector<int>> buildings;
vector<vector<bool>> visited;

vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

bool valid(int row, int col, int curVal) {
  return (row >= 0 && row < n && col >= 0 && col < m && buildings[row][col] <= curVal && !visited[row][col]);
}

void floodfill(int row, int col) {
  rep(i, 0, 4) {
    int newRow = row + dy[i];
    int newCol = col + dx[i];
    if (valid(newRow, newCol, buildings[row][col])) {
      visited[newRow][newCol] = true;
      floodfill(newRow, newCol);
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  cin >> n >> m;
  buildings = vector<vector<int>>(n, vector<int>(m));
  visited = vector<vector<bool>>(n, vector<bool>(m, false));
  map<int, vector<pair<int, int>>> heightsToLocs;
  rep(i, 0, n)
    rep(j, 0, m) {
      cin >> buildings[i][j];
      if (buildings[i][j] > 1)
        heightsToLocs[buildings[i][j]].emplace_back(i, j);
    }
  
  vector<pair<int, vector<pair<int, int>>>> sortedHeightsToLocs;
  for (auto e : heightsToLocs) sortedHeightsToLocs.emplace_back(e.first, e.second);
  sort(all(sortedHeightsToLocs));
  reverse(all(sortedHeightsToLocs));
  
  int count = 0;

  for (auto floor : sortedHeightsToLocs) {
    int h = floor.first;
    for (auto loc : floor.second) {
      if (!visited[loc.first][loc.second]) {
        count++;
        floodfill(loc.first, loc.second);
      }
    }
  }
  
  cout << count << endl;

  return 0;  
}
