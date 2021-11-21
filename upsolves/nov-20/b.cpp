#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string phrase;
    getline(cin, phrase);
    phrase += ' ';
    int a, b; cin >> a >> b;

    vi wordLen(sz(phrase), 0);
    vi wordStart(sz(phrase), 0);

    int curStart = 0, len = 0;
    for (int i = 0; i < sz(phrase); i++) {
        if (phrase[i] == ' ') {
            wordLen[curStart] = len;
            curStart = i + 1;
            wordStart[i] = curStart;
            len = 0;
            continue;
        }
        wordStart[i] = curStart;
        len++;
    }

    for (int jmp = a; jmp <= b; jmp++) {
        int loc = 0;
        int width = 0;
        while (loc + jmp < sz(wordStart)) {
            width += wordLen[loc] + 1;
            loc = wordStart[loc + jmp];
        }
        width += wordLen[loc];
        cout << width << nl;
    }

    return 0;
}

