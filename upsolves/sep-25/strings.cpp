#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl endl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string s;
int i, j, k;
char c;

bool isPalindrome() {
    i--; j--;
    while (i < j)
        if (s[i++] != s[j--])
            return false;
    return true;
}

void cut() {
    i--; j--;
    string first = s.substr(0, i);
    string second = s.substr(i, j - i + 1);
    string third = s.substr(j + 1);
    string t = first + third;
    s = t.substr(0, k) + second + t.substr(k);
}

void rev() {
    i--;
    reverse(s.begin() + i, s.begin() + j);
}

void ins() {
    i--;
    s.insert(s.begin() + i, c);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m; cin >> n >> m;
    cin >> s;

    for (int t = 0; t < m; t++) {
        char q; cin >> q;
        if (q == 'Q') {
            cin >> i >> j;
            cout << (isPalindrome() ? "YES" : "NO") << nl;
        } else {
            int q; cin >> q;
            if (q == 1) {
                cin >> i >> j >> k;
                cut();
            } else if (q == 2) {
                cin >> i >> j;
                rev();
            } else {
                cin >> i >> c;
                ins();
            }
        }
    }

    return 0;
}
