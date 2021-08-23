#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int t) {
    int s, b; cin >> s >> b;
    int m; cin >> m;

    cout << "Practice #" << t+1 << ": " << s << ' ' << b << endl;
    int brownies = b;
    for (int i = 0; i < m; i++) {
        int g; cin >> g;
        while (brownies - g < 1) brownies *= 2;
        brownies -= g;

        cout << g << ' ' << brownies << endl;
    }
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    for (int i = 0; i < n; i++) solve(i);

    return 0;    
}
