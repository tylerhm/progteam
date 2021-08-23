#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

set<char> vowels;
vector<int> charTypes;
string inp;
ll ans;

void backtrack(int index) {
    if (index == charTypes.size()) return;

    // changeable
    if (charTypes[index] == 0) {
        // see what we can make it
        int i = index - 1;
        if (i < 0) i += 2;

        // both
        if (charTypes[i] == 0) {
            ans *= 26;
            charTypes[index] = 1;
            backtrack(index + 1);
            charTypes[index] = 2;
            backtrack(index + 1);
        } else if (charTypes[i] == 1) {
            ans *= 20;
            backtrack(index + 1);
        } else {
            ans *= 6;
            backtrack(index + 1);
        }
    } else backtrack(index + 1);
}

void solve(int t) {
    cout << "String #" << t+1 << ": ";

    string inp; cin >> inp;

    // check if the string is valid
    charTypes.resize(inp.length());
    bool q = false;
    for (int i = 0; i < inp.length() - 1; i++) {
        if (inp[i] == '?') {
            charTypes[i] = 0;
            q = true;
            continue;
        }

        if (vowels.count(inp[i])) charTypes[i] = 1;
        else charTypes[i] = 2;

        if (inp[i + 1] == '?') continue;
        if (vowels.count(inp[i]) != vowels.count(inp[i + 1])) continue;

        cout << 0 << endl << endl;
        return;
    }

    if (!q) {
        cout << 1 << endl << endl;
        return;
    }

    int last = charTypes.size() - 1;
    if (inp[last] == '?') charTypes[last] = 0;
    else if (vowels.count(inp[last])) charTypes[last] = 1;
    else charTypes[last] = 2;

    ans = 1;
    backtrack(0);

    if (ans == 1) ans = 0;
    cout << ans;

    cout << endl << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');
    vowels.insert('o');
    vowels.insert('u');
    vowels.insert('y');

    int n; cin >> n;
    for (int i = 0; i < n; i++) solve(i);

    return 0;    
}
