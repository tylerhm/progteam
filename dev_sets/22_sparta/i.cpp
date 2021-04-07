#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MAX_N (int)10e6

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    vector<ll> precomp(MAX_N + 10, 0);

    for (ll i = 1; i <= MAX_N; i++)
        for (ll j = i + 1; i*j <= MAX_N; j++)
            for (ll k = j + 1; i*j*k <= MAX_N; k++)
                precomp[i*j*k]++;
    
    for (ll i = 1; i <= MAX_N; i++)
        precomp[i] += precomp[i - 1];

    ll t; cin >> t;
    rep(tt, 0, t) {
        ll n; cin >> n;
        cout << precomp[n] << "\n";
    }

    return 0;
}
