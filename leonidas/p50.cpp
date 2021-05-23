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
    set<string> reserved;
    rep(i, 0, n) {
        string r; cin >> r;
        reserved.insert(r);
    }

    int m; cin >> m;
    string line;
    getline(cin, line); // garb
    getline(cin, line);

    cout << line << endl;

    return 0;    
}
