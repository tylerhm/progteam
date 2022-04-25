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

    ll n, m; cin >> n >> m;
    map<int, int> lastRead;

    for (int i = 1; i <= m; i++) {
        int p; cin >> p;
        lastRead[p] = i;
        ll total = 0;
        for (auto [_, r] : lastRead)
            total += i - r;
        total += (n - sz(lastRead)) * i;
        cout << total << "\n";
    }

    return 0;
}

