#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int t) {
    cout << "Case #" << t << ": ";

    string one, two; cin >> one >> two;

    string doubled = one + one;
    string reversed = doubled;
    reverse(all(reversed));
    if (doubled.find(two) != string::npos || reversed.find(two) != string::npos)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        solve(i);

    return 0;    
}
