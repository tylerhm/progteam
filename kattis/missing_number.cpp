#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    string line; cin >> line;

    int curLen = 1;
    int curLoc = 0;
    for (int i = 1; i <= n - 1; i++) {
        int val = stoi(line.substr(curLoc, curLen));
        if (val != i) {
            cout << i << "\n";
            return 0;
        }
        curLoc += curLen;
        if (i >= 9) curLen = 2;
    }

    cout << n << "\n";
    return 0;
}

