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

    for (int i = 0; i < n; i++) {
        int t, tt; cin >> t >> tt;

        vector<int> tracks(tt);
        for (auto &x : tracks) cin >> x;

        ll cost = 0;
        for (int i = 0; i < tt - 1; i++) {
            bool behind = tracks[i + 1] > tracks[i];

            int forwards, backwards;
            if (behind) {
                forwards = tracks[i + 1] - tracks[i] - 1;
                backwards = tracks[i] + (t - tracks[i + 1]) + 1;
            } else {
                forwards = t - tracks[i] + tracks[i + 1] - 1;
                backwards = tracks[i] - tracks[i + 1] + 1;
            }

            cost += min(forwards, backwards);
        }

        cout << cost << endl;
    }

    return 0;    
}
