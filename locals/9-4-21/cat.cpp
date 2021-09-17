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

    int y, m; cin >> y >> m;

    int months = y*12 + m;
    
    int A = min(12, months);
    months -= A;
    int B = min(12, months);
    months -= B;
    int C = months;

    int fin = A*15 + B*9 + C*4;

    int years = fin / 12;
    int leftover = fin % 12;

    cout << years << ' ' << leftover << endl;

    return 0;    
}
