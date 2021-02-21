#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int minRain = (int)10e9;

vector<int> c, u;
vector<vector<int>> adjList;

void dfs(int index, int curReqFlow) {
  minRain = min(minRain, curReqFlow);

  for (int next : adjList[index])
    dfs(next, max(c[next]-u[next], curReqFlow-u[next]));
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, w; cin >> n >> w;

  c = vector<int>(n+1);
  u = vector<int>(n+1);
  adjList = vector<vector<int>>(n+1);
  for (int i = 1; i <= n; i++) {
    int di, ci, ui; cin >> di >> ci >> ui;
    adjList[di].push_back(i);
    c[i] = ci;
    u[i] = ui;
  }

  dfs(0, w);

  cout << minRain << '\n';
}