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

    int n; cin >> n;
    string val; cin >> val;
    
    int index = 0;
    int size = 1;
    for (int i = 1; i <= n; i++) {
        if (val.substr(index, size) != to_string(i)) {
            cout << i << "\n";
            return 0;
        }

        if (i == 9)
            size = 2;
        else if (i == 99)
            size = 3;

        if (i < 10)
            index++;
        else if (i < 100)
            index += 2;
        else
            index += 3;
    }

    return 0;    
}
