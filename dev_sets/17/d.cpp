#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;
struct Point {
  int x, y;
};

bool operator<(const Point &a, const Point &b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}

set<Point> points;
map<int, vector<Point>> rows, cols;

bool validPair(Point &p1, Point &p2) {
  if (p1.x > p2.x || p1.y > p2.y) return false;
  int x1 = p1.x;
  int y1 = p1.y;
  int x2 = (p1.x != p2.x ? p2.x : x1 + (p2.y - p1.y));
  int y2 = (p1.y != p2.y ? p2.y : y1 + (p2.x - p1.x));
  return points.count(Point{x1, y2}) &&
         points.count(Point{x2, y1}) &&
         points.count(Point{x2, y2});
}

bool solve() {

  int n;
  if (!(cin >> n))
      return false;

  points.clear();
  rows.clear();
  cols.clear();

  for (int i = 0; i < n; i++) {
      int x, y; cin >> x >> y;
      Point p {x, y};
      points.insert(p);
      cols[x].push_back(p);
      rows[y].push_back(p);
  }

  int maxSize = 0;
  for (auto &col: cols) {
    bool doCols = (col.second.size() > n / col.second.size());
    for (Point &p1 : col.second) {
      if (doCols) {
        for (Point &p2 : rows[p1.y]) {
          if (p2.x - p1.x <= maxSize) continue;
          if (validPair(p1, p2)) maxSize = p2.x - p1.x;
        }
      }
      else {
        for (Point &p2 : col.second) {
          if (p2.y - p1.y <= maxSize) continue;
          if (validPair(p1, p2)) maxSize = p2.y - p1.y;
        }
      }
    }
  }
  cout << maxSize << nl;
  return true;
}

int main()
{
  while(solve());
  return 0;
}
