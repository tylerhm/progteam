#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<char, set<char>> alph;

void solve(int t) {
    cout << "Test case #" << t << ":" << endl;
    int p; cin >> p;

    for (int i = 0; i < 26; i++) alph['a' + i] = {(char)('a' + i)};
    for (int i = 0; i < p; i++) {
        char one, two; cin >> one >> two;
        alph[one].insert(two);
        alph[two].insert(one);
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        string inp; cin >> inp;
        cout << inp << ' ';
        
        bool valid = true;
        int lo = 0, hi = inp.length() - 1;
        while (lo < hi) {
            if (alph[inp[lo++]].count(inp[hi--])) continue;
            valid = false;
            break;
        }

        cout << (valid ? "YES" : "NO") << endl;
    }
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    for (int i = 0; i < n; i++) solve(i + 1);

    return 0;    
}
