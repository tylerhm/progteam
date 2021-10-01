#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int t) {
    cout << "Case " << t+1 << ":" << endl;

    int n; cin >> n;
    vi pellets(n);
    for (auto &x: pellets) cin >> x;

    vi lis(n, 1), lds(n, 1);

    // calc lis up to and including i
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (pellets[j] <= pellets[i])
                lis[i] = max(lis[i], lis[j] + 1);

    // calc lds after and including i
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j > i; j--)
            if (pellets[j] <= pellets[i])
                lds[i] = max(lds[i], lds[j] + 1);
    
    int mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, lis[i] + lds[i] - 1);
    
    cout << "Dynamo ate " << mx << " food pellet(s)." << endl << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    rep(tt, 0, t) solve(t);

    return 0;
}
