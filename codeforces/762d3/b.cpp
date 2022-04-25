#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tt) {
  ll n; cin >> n;
  unordered_set<int> ans;
  for (ll i = 1; i*i <= n; i++) {
    if (i*i <= n) ans.insert(i*i);
    if (i*i*i <= n) ans.insert(i*i*i);
  }
  cout << ans.size() << nl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
        solve(tt);

    return 0;
}

