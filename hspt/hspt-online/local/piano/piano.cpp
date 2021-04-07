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

    int cases; cin >> cases;
    for (int i = 0; i < cases; i++) {
        string in; cin >> in;
        for (int i = 0; i < in.length(); i++)
            cout << "L";
        cout << "\n";
    }

    return 0;    
}
