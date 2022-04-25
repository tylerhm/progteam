#include<iostream>
#include<vector>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tt) {
  string in; cin >> in;
  int len = in.length();
  if (len & 1) {
    cout << "NO\n";
    return;
  }

  if (in.substr(0, len/2) == in.substr(len/2, len/2))
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
      solve(tt);

    return 0;
}

