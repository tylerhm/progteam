#include <iostream>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
  int n; cin >> n;
  ll prev; cin >> prev;
  ll cur; cin >> cur;
  ll ans = prev * cur;
  for (int i = 0; i < n - 2; ++i) {
    prev = cur;
    cin >> cur;
    ans = max(ans, prev * cur);
  }

  cout << ans << nl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc)
      solve(tc);

    return 0;
}

