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

    int n, c; cin >> n >> c;

    vector<ll> w(n);
    for (auto &val : w) cin >> val;

    sort(all(w));
    
    for (int i = n-1; i >= 0; i--) {
        
    }

    return 0;    
}
