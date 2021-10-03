#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct trie {
    bool terminal = false;
    int terminalChildren = 0;
    int run = -1;
    map<char, trie> children;

    trie() {}
    void insert(string &s, int idx) {
        if (idx == sz(s) - 1) terminalChildren++;
        if (idx == sz(s)) terminal = true;
        else children[s[idx]].insert(s, idx + 1);
    }
};

int getRun(trie &t) {
    if (t.run != -1) return t.run;
    int run = 0;
    for (auto &[ch, tt] : t.children)
        if (tt.terminal)
            run = max(run, getRun(tt));
    return t.run = t.terminalChildren + run;
}

int pathLen(trie &t) {
    int m1 = 0, m2 = 0;
    for (auto &[ch, tt] : t.children)
        if (tt.terminal) {
            int run = getRun(tt);
            if (run > m1) {
                m2 = m1;
                m1 = run;
            } else if (run > m2)
                m2 = run;
        }
    return t.terminalChildren + m1 + m2 + t.terminal;
}

int best;
void go(trie &t) {
    best = max(best, pathLen(t));
    for (auto &[ch, tt] : t.children)
        go(tt);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    trie t;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        reverse(all(s));
        t.insert(s, 0);
    }

    best = -1;
    go(t);
    cout << best << endl;

    return 0;
}
