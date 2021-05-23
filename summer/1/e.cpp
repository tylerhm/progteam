#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void nextTest(string& test, int k) {
    for (int i = test.length(); i >= 0; i--) {
        test[i]++;
        if (test[i] >= 'a' + k)
            test[i] = 'a';
        else
            return;
    }
    test = 'a' + test;
}

void solve(int tt) {
    int n, m, k; cin >> n >> m >> k;
    string word; cin >> word;

    string test = "a";
    while (word.find(test) != string::npos) nextTest(test, k);
    cout << test << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    rep(tt, 0, t) solve(tt);

    return 0;    
}
