#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int weight(int a) {
    int sum = 0;
    int len = 0;
    while (a > 0) {
        sum += a % 10;
        len++;
        a /= 10;
    }

    return sum * len;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int one, two; cin >> one >> two;

    int w1 = weight(one);
    int w2 = weight(two);

    if (w1 > w2) cout << 1;
    else if (w2 > w1) cout << 2;
    else cout << 0;
    cout << endl;

    return 0;    
}
