#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const double constant = 3.1415926535897932384626 / 2;

void solve(int tc) {
    double r, v; cin >> r >> v;
    cout << "Case " << tc << ": " << (r/v) * constant << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cout << fixed << setprecision(8);

    int t; cin >> t;
    for (int i = 1; i <= t; i++)
      solve(i);

    return 0;
}

