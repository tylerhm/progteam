#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// Our modulo.
const ll mod = 1'000'000'007;

ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}

void solve(int t) {
    cout << "Genome #" << t << ": "; 

    string a, c, t, g; cin >> a >> c >> t >> g;
    string genome; cin >> genome;
    ll n; cin >> n;

    // Determine how many as, cs, ts, and gs each letter will create, given our current scheme.
    map<char, map<char, ll>> creations;
    for (char ch : a) creations['a'][ch]++;
    for (char ch : c) creations['c'][ch]++;
    for (char ch : t) creations['t'][ch]++;
    for (char ch : g) creations['g'][ch]++;

    // Count occurances of each letter in the genome.
    map<char, ll> genomeCounts;
    for (char ch : genome) genomeCounts[ch]++;

    // Time for fast mod pow!
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    rep(i, 0, t)
        solve(t);

    return 0;    
}
