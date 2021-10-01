#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
int cnt;

void go(int idx, int depth, string str) {
    if (cnt == n / 2) return;
    if (depth > n - idx) return;
    
    if (idx == n) {
        cout << str << endl;
        cnt++;
        return;
    }

    if (depth > 0) {
        go(idx + 1, depth - 1, str + ")");
    }
    go(idx + 1, depth + 1, str + "(");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    rep(tt,0,t) {
        cin >> n;
        n *= 2;
        cnt = 0;
        go(0, 0, "");
    }

    return 0;
}
