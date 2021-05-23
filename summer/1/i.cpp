#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tt) {
    map<string, int> losses;
    vector<string> teams;
    string t1, t2;
    int g1, g2;
    rep(i, 0, 16) {
        cin >> t1 >> t2;
        cin >> g1 >> g2;

        teams.push_back(t1);
        teams.push_back(t2);

        if (g1 > g2) losses[t2]++;
        else losses[t1]++;
    }

    for (string t : teams)
        if (losses[t] == 0) {
            cout << t << endl;
            return;
        }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    rep(tt, 0, t) solve(tt);

    return 0;    
}
