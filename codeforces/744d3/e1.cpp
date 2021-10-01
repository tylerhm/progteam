#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    int val; cin >> val;
    deque<int> ans; ans.push_back(val);
    for (int i = 1; i < n; i++) {
        cin >> val;
        if (val <= ans[0]) ans.push_front(val);
        else ans.push_back(val);
    }

    for (int i : ans) cout << i << ' ';
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    rep(tt, 0, t) solve();

    return 0;
}
