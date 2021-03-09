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

  int n; cin >> n;
  int maxSpeed = -1;
  int lastT, lastD; cin >> lastT >> lastD;
  rep(i, 0, n-1) {
    int t, d; cin >> t >> d;
    maxSpeed = max(maxSpeed, (lastD-d)/(lastT-t));
    lastD = d;
    lastT = t;
  }

  cout << maxSpeed << '\n';

  return 0;  
}
