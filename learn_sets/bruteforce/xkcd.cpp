#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

char word[42];
int n;

string vowels = "aeiouy";

char getChar(int val) {
    return 'a' - 1 + val;
}

bool invalid(int val) {
    if (n <= 2) return false;
    char c = getChar(val);
    return c >= word[n-3];
}

void go(int idx, int sum, int last) {
    // we only got here if it was valid
    if (idx == n) {
        rep(i, 0, n) cout << word[i];
        cout << endl;
        return;
    }

    // last one, so we must ensure that our last place is valid
    if (idx == n - 1) {
        int lastChar = 42 - sum;
        char c = getChar(lastChar);
        if (lastChar > 26 ||
            lastChar <= last ||
            vowels.find(c) != string::npos ||
            invalid(lastChar)
        ) return;
        word[idx] = getChar(lastChar);
        go(idx + 1, sum + lastChar, lastChar);
        return;
    }

    rep(i, 1, 27) {
        if (i >= last) return;
        if (sum + i >= 42) return;
        char c = getChar(i);
        if (vowels.find(c) == string::npos) {
            word[idx] = c;
            go(idx + 1, sum + i, i);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> n;
    while (n != 42) {
        cout << "XKCD-like name(s) of length: " << n << endl;
        if (n >= 8) cout << "Mostly Harmless" << endl;
        else go(0, 0, INT_MAX);
        cin >> n;
    }

    cout << "The answer to life, the universe and everything!" << endl;

    return 0;
}
