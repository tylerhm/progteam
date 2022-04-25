#include <iostream>
#include <vector>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tt) {
  string a, c; cin >> a >> c;
  reverse(all(a));
  reverse(all(c));

  if (sz(a) > sz(c)) {
    cout << -1 << nl;
    return;
  }

  string ans = "";
  int cIdx = 0;
  for (int i = 0; i < sz(a); i++) {
    int dig = a[i] - '0';
    if (cIdx >= sz(c)) {
      cout << -1 << nl;
      return;
    }

    int curC = c[cIdx++] - '0';
    if (curC < dig) {
      if (cIdx >= sz(c)) {
        cout << -1 << nl;
        return;
      }
      curC += (c[cIdx++] - '0') * 10;
    }

    int needed = curC - dig;
    if (needed >= 10 || needed < 0) {
      cout << -1 << nl;
      return;
    }
    ans += '0' + needed;
  }

  while (cIdx < sz(c))
    ans += c[cIdx++];

  int numZeros = 0;
  while (ans[sz(ans) - 1 - numZeros] == '0')
    numZeros++;

  ans = ans.substr(0, sz(ans) - numZeros);

  reverse(all(ans));
  cout << ans << nl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int t; cin >> t;
  for (int tt = 1; tt <= t; tt++)
    solve(tt);

  return 0;
}

