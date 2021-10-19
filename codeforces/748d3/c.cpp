#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/*
3
10 6
8 7 5 4 9 4
2 8
1 1 1 1 1 1 1 1
12 11
1 2 3 4 5 6 7 8 9 10 11
*/

void solve(int tt) {
    int n, k; cin >> n >> k;
    vector<int> idx;
    map<int, int> mice;
    for (int i = 0; i < k; i++) {
        int loc; cin >> loc;
        mice[loc]++;
        idx.push_back(loc);
    }

    sort(all(idx));
    reverse(all(idx));

    int catMoves = n;
    int found = 0;
    int i = 0;
    while (i < sz(idx) && found < catMoves) {
        
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 0; tt < t; tt++) solve(tt);

    return 0;
}
