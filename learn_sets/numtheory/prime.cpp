#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define LIM (int)1e7 + 1
bitset<LIM> notPrime;
void precomp() {
    for (int i = 2; i*i < LIM; i++)
        if (notPrime[i] == 0) {
            for (int j = 2*i; j < LIM; j += i)
                notPrime[j] = 1;
        }
}
// hello this is a comment
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    precomp();
    int t; cin >> t;
    while (t--) {
        int val; cin >> val;
        cout << (notPrime[val] ? 0 : 1) << endl;
    }

    return 0;
}
