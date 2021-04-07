#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int t, int n) {
    vector<int> neighbors(n);
    vector<vector<bool>> adjCandidates(n, vector<bool>(n, false));

    bool solving = true;
    int p1 = 1, p2 = 2, p3 = 3;
    while (solving) {
        cout << p1 << " " << p2 << " " << p3 << endl;
        
        int median; cin >> median;

        // estabilish adjacency candidates, and if they are strong then link them
        if (median == p1) {
            adjCandidates[p1][p2] = true;
            adjCandidates[p1][p3] = true;

            if (adjCandidates[p2][p1])
                neighbors[p2] = p1;
            if (adjCandidates[p3][p1])
                neighbors[p3] = p1;
        }
        else if (median == p2) {
            adjCandidates[p2][p1] = true;
            adjCandidates[p2][p3] = true;

            if (adjCandidates[p1][p2])
                neighbors[p1] = p2;
            if (adjCandidates[p3][p2])
                neighbors[p3] = p2;
        }
        else if (median == p3) {
            adjCandidates[p3][p2] = true;
            adjCandidates[p3][p1] = true;

            if (adjCandidates[p2][p3])
                neighbors[p2] = p3;
            if (adjCandidates[p1][p3])
                neighbors[p1] = p3;
        }

        
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t, n, q; cin >> t >> n >> q;
    for (int tt = 0; tt < t; tt++)
        solve(tt, n);

    return 0;    
}
