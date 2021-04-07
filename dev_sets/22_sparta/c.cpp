#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int go() {
    string inp; cin >> inp;
    bitset<40> bits(inp);

    if (bits.count() == inp.length()) return 0;

    ll parsed = stoll(inp, NULL, 2);

    // inline bfs faster?
    queue<ll> q;
    map<ll, ll> dists;

    dists[parsed] = 1;
    q.push(parsed);

    while (!q.empty()) {
        ll curCorral = q.front(); q.pop();
        ll dist = dists[curCorral];

        // try all ks
        for (ll k = 1; k <= inp.length(); k++) {
            // shift everything to the right k times, and or it.
            // 10110001 k = 2 = 10110101
            ll newCorral = curCorral | (curCorral >> k);
            bitset<40> bits(newCorral);

            if (bits.count() == inp.length()) return dist;

            if (!dists[newCorral]) {
                dists[newCorral] = dist + 1;
                q.push(newCorral);
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cout << go() << "\n";

    return 0;    
}
