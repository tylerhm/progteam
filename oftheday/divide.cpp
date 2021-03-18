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

    ll n, d; cin >> n >> d;
    vector<ll> solved(n);
    ll sum = 0;
    rep(i, 0, n) {
        ll q; cin >> q;
        sum += q;
        solved[i] = q;
    }
    ll dps = d/sum;
    for (ll s : solved)
        cout << s*dps << "\n";

    return 0;    
}
