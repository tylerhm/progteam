#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
    string s; cin >> s;
    int cnt = 0;
    for (char c : s) if (c == 'N') cnt++;
    cout << (cnt == 1 ? "NO" : "YES") << nl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc)
      solve(tc);

    return 0;
}

