#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  string a, b; cin >> a >> b;
  string acopy = a, bcopy = b;
  
  // get leftmost carry index
  int i;
  for (i = 0; i < a.size() && i < b.size() && (a[i]-'0') + (b[i]-'0') < 10; i++);

  // this is the index we need to fix, might ripple left though
  for (; i >= 0 && (a[i]-'0') + (b[i]-'0') >= 9; i--);

  bool sizeAdj = false;
  if (i == -1) {
    a = "0" + a;
    i++;
    sizeAdj = true;
  }

  // a
  string highA = "";
  for (int j = 0; j < a.size(); j++) {
    if (j == i)
      a[j]++;
    else if (j > i)
      a[j] = '0';
  }

  a = a.substr(i);
  acopy = acopy.substr(i);
  cout << a << ' ' << acopy << '\n';
  cout << stoll(a) - stoll(acopy) << '\n';

  return 0;
}