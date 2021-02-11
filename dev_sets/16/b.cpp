#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

#define GOLD '#'
#define PAPER '.'

int n, m;
vector<pair<pair<int, int>, pair<int, int>>> solutions;
vector<string> leaf;
int paperCount = 0;

bool valid(int row, int col) { return row >= 0 && row < n && col >= 0 && col < m; }

void getPaperCount() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (leaf[i][j] == PAPER)
                paperCount++;
}

bool isGold(string inp) {
    for (char c : inp)
        if (c != GOLD)
            return false;
    return true;
}

string invert(string inp) {
    for (auto &x : inp) {
        if (x == GOLD)
            x = PAPER;
        else
            x = GOLD;
    }
    return inp;
}

void horizontal() {
    int row, drow, foundPaper;
    for (row = 0; row < n; row++) {
        bool validFold = true;
        foundPaper = 0;
        for (drow = 1; valid(row-drow+1, 0) && valid(row+drow, 0); drow++) {
            string one = "", two = "";
            for (int i = 0; i < m; i++) {
                one += leaf[row-drow+1][i];
                two += leaf[row+drow][i];
            }
            if (one != invert(two)) {
                validFold = false;
                break;
            }
            foundPaper += one.size();
        }
        if (validFold && foundPaper == paperCount)
            solutions.push_back({{row+1, 1},{row+1, m}});
    }
}

void vertical() {
    int col, dcol, foundPaper;
    for (col = 0; col < m; col++) {
        bool validFold = true;
        foundPaper = 0;
        for (dcol = 1; valid(0, col-dcol+1) && valid(0, col+dcol); dcol++) {
            string one = "", two = "";
            for (int i = 0; i < n; i++) {
                one += leaf[i][col-dcol+1];
                two += leaf[i][col+dcol];
            }
            if (one != invert(two)) {
                validFold = false;
                break;
            }
            foundPaper += one.size();
        }
        if (validFold && foundPaper == paperCount)
            solutions.push_back({{1, col+1},{n, col+1}});
    }
}

void fortyFive() {

    // left wall
    int row, dist, foundPaper = 0;
    for (row = 0; row < n; row++) {
        bool validFold = true;
        foundPaper = 0;
        int moved = 0;
        for (dist = 1; valid(row-dist, 0) && valid(row, dist); dist++) {
            string one = "", two = "";
            int sr1 = row-dist, sc1 = 0;
            int sr2 = row, sc2 = dist;
            for (int i = 0; valid(sr1-i, sc1+i) && valid(sr2-i, sc2+i); i++) {
                one += leaf[sr1-i][sc1+i];
                two += leaf[sr2-i][sc2+i];
            }
            if (one != invert(two)) {
                validFold = false;
                break;
            }
            foundPaper += one.size();
            moved++;
        }
        if (validFold && foundPaper == paperCount)
            solutions.push_back({{row+1, 1},{row+1-moved, 1+moved}});
    }


    // bottom wall
    int col;
    for (col = 0; col < m; col++) {
        bool validFold = true;
        foundPaper = 0;
        int moved = 0;
        for (dist = 1; valid(n-1, col+dist) && valid(n-1-dist, col); dist++) {
            string one = "", two = "";
            int sr1 = n-1, sc1 = col+dist;
            int sr2 = n-1-dist, sc2 = col;
            for (int i = 0; valid(sr1-i, sc1+i) && valid(sr2-i, sc2+i); i++) {
                one += leaf[sr1-i][sc1+i];
                two += leaf[sr2-i][sc2+i];
            }
            if (one != invert(two)) {
                validFold = false;
                break;
            }
            moved++;
            foundPaper += one.size();
        }
        if (validFold && foundPaper == paperCount)
            solutions.push_back({{n, col+1},{n-moved, col+1+moved}});
    }
}

void oneThirtyFive() {
    // left wall
    int row, dist, foundPaper = 0;
    for (row = 0; row < n; row++) {
        bool validFold = true;
        foundPaper = 0;
        int moved = 0;
        for (dist = 1; valid(row+dist, 0) && valid(row, dist); dist++) {
            string one = "", two = "";
            int sr1 = row+dist, sc1 = 0;
            int sr2 = row, sc2 = dist;
            for (int i = 0; valid(sr1+i, sc1+i) && valid(sr2+i, sc2+i); i++) {
                one += leaf[sr1+i][sc1+i];
                two += leaf[sr2+i][sc2+i];
            }
            if (one != invert(two)) {
                validFold = false;
                break;
            }
            foundPaper += one.size();
            moved++;
        }
        if (validFold && foundPaper == paperCount)
            solutions.push_back({{row+1, 1},{row+1+moved, 1+moved}});
    }


    // top wall
    int col;
    for (col = 0; col < m; col++) {
        bool validFold = true;
        foundPaper = 0;
        int moved = 0;
        for (dist = 1; valid(0, col+dist) && valid(dist, col); dist++) {
            string one = "", two = "";
            int sr1 = 0, sc1 = col+dist;
            int sr2 = dist, sc2 = col;
            for (int i = 0; valid(sr1+i, sc1+i) && valid(sr2+i, sc2+i); i++) {
                one += leaf[sr1+i][sc1+i];
                two += leaf[sr2+i][sc2+i];
            }
            if (one != invert(two)) {
                validFold = false;
                break;
            }
            moved++;
            foundPaper += one.size();
        }
        if (validFold && foundPaper == paperCount)
            solutions.push_back({{1, col+1},{1+moved, col+1+moved}});
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	cin >> n >> m;
    leaf = vector<string>(n);
    for (auto &x: leaf) cin >> x;
    solutions.clear();
    getPaperCount();

    horizontal();
    vertical();
    fortyFive();
    oneThirtyFive();

    if (solutions.size() == 0) {
        cout << "LOL WA" << nl;
        return 0;
    }

    sort(all(solutions));
    auto ans = solutions[0];
    cout << ans.first.first << ' ' << ans.first.second << ' ' << ans.second.first << ' ' << ans.second.second << nl;

    return 0;
}
