#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct result {
    char dir;
    int row, col;
    string word;
    result(char d, int r, int c, string w) {
        dir = d;
        row = r;
        col = c;
        word = w;
    }
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int r, c;

char find(vector<string> &board, string word, int row, int col) {
    for (int i = 0; i < 4; i++) {
        bool valid = true;
        int ro = row;
        int co = col;
        for (int cIdx = 0; cIdx < word.length(); cIdx++) {
            if (board[ro][co] != word[cIdx]) {
                valid = false;
                break;
            }
            ro += dy[i];
            co += dx[i];
            if (ro < 0) ro += r;
            if (co < 0) co += c;
            if (ro >= r) ro -= r;
            if (co >= c) co -= c;
        }
        if (valid) {
            if (i == 0) return 'R';
            if (i == 1) return 'L';
            if (i == 2) return 'D';
            if (i == 3) return 'U';
            return '*';
        }
    }
    return '*';
}

void solve(int t) {
    cout << "Word search puzzle #" << t << ":" << endl;

    cin >> r >> c;
    vector<string> board(r);
    for (auto &x : board) cin >> x;

    int wc; cin >> wc;
    vector<result> ans;
    for (int i = 0; i < wc; i++) {
        string word; cin >> word;

        bool found = false;
        for (int row = 0; row < r && !found; row++) {
            for (int col = 0; col < c && !found; col++) {
                char dir = find(board, word, row, col);
                if (dir != '*') {
                    ans.emplace_back(dir, row, col, word);
                    found = true;
                }
            }
        }
    }

    for (auto res : ans) {
        cout << res.dir << ' ' << res.row+1 << ' ' << res.col+1 << ' ' << res.word << endl;
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
