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

    int s, b; cin >> s >> b;

    int brownies = b;
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int group; cin >> group;
        while (brownies <= group) brownies *= 2;
        brownies -= group;
        cout << group << ' ' << brownies << endl;
    }

    return 0;    
}
