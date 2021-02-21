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

  string a, b; cin >> a >> b;

  int sza = 0, szb = 0;
  for (char c : a)
    if (c == 'S')
      sza++;
  for (char c : b)
    if (c == 'S')
      szb++;
  int res = sza*szb;


  for (int i = 0; i < res; i++)
    cout << "S(";
  cout << 0;
  for (int i = 0; i < res; i++)
    cout << ")";
}