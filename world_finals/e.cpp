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

    int n, k; cin >> n >> k;
    vector<int> inc(n+1, 0), dy(n+1, 0);
    for (int i = 0; i < k; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        a--; b--;
        if (c == 'R') {
            inc[a]++;
            inc[b+1]--;
        } else if (c == 'D') {
            inc[a]--;
            inc[b+1]++;
        } else if (c == 'H') {
            dy[a]++;
            if (!((b - a) & 1))
                dy[(a + b) / 2 + 1] -= 2;
            else
                dy[(a + b) / 2 + 1] -= 1,
                dy[(a + b) / 2 + 2] -= 1;
            dy[b+2]++;
        } else {
            dy[a]--;
            if (!((b - a) & 1))
                dy[(a + b) / 2 + 1] += 2;
            else
                dy[(a + b) / 2 + 1] += 1,
                dy[(a + b) / 2 + 2] += 1;
            dy[b+2]--;
        }
    }

    ll val = 0;
    int d = 0;
    for (int i = 0; i < n; i++) {
        d += dy[i];
        val += inc[i] + d;
        cout << val << endl;
    }

    return 0;
}
