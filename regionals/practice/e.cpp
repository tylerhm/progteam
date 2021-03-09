#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<int, string> solutions {
  {1, "Either"},
  {2, "Odd"},
  {3, "Either"},
  {4, "Even"},
  {5, "Either"},
  {6, "Odd"},
  {7, "Either"},
  {8, "Even"},
  {9, "Either"},
  {10, "Odd"}
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n; cin >> n;
  cout << solutions[n] << '\n';

  return 1;  
}
