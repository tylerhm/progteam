#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int sr, sc, er, ec;
vector<int> lens;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        lens.resize(l);
        for (auto &x : lens) cin >> x;

        cin >> sr >> sc;
        cin >> er >> ec;

        int miCol = sc;
        for (int i = min(sr, er); i <= max(sr, er); i++) {
            miCol = min(lens[i], miCol);
        }

        // we've now moved up the correct number of rows
        int dist = abs(sr - curRow);
        int curRow = er, curCol = miCol;

    return 0;    
}
