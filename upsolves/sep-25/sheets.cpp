#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll t, p, v;

void flipIt() {
    ll width, height;
    width = height = 1LL << p;
    ll depth = 0;
    ll stck = 1;

    v--;
    ll row = v / width;
    ll col = v % width;

    for (ll i = 0; i < p; i++) {
        // flip up
        if (row >= height >> 1) {
            // it is being flipped
            row = height - row - 1;
            depth = stck + (stck - depth - 1);
        }

        height >>= 1;
        stck <<= 1;

        // flip left
        if (col >= width >> 1) {
            col = width - col - 1;
            depth = stck + (stck - depth - 1);
        }

        width >>= 1;
        stck <<= 1;
    }

    cout << depth+1 << nl;
}

void unFlipIt() {
    ll width, height;
    width = height = 1;

    ll stck = (1LL << p)*(1LL << p);
    ll depth = v-1;
    ll row, col;
    row = col = 0;

    for (ll i = 0; i < p; i++) {
        // flip right
        if (depth >= stck >> 1) {
            col = width + (width - col - 1);
            depth = stck - depth - 1;
        }

        width <<= 1;
        stck >>= 1;
        
        // flip down
        if (depth >= stck >> 1) {
            row = height + (height - row - 1);
            depth = stck - depth - 1;
        }

        height <<= 1;
        stck >>= 1;
    }

    cout << (row*width + col)+1 << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> t >> p >> v;
        if (t == 1) flipIt();
        else unFlipIt();
    }

    return 0;
}

