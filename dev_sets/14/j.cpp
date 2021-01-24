#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

#define FILL ' '

pair<int, int> clickToIndex(char row, int col) { return {abs(col-12), row-'a'}; }
bool valid(int row, int col) { return (row >= 0 && row < 12 && col >= 0 && col < 10); }

vector<vector<char>> board;
vector<pair<int, int>> diffs;

void flood(pair<int, int> coord, char active) {
    for (auto d : diffs) {
        pair<int, int> nc;
        nc.first = coord.first + d.first;
        nc.second = coord.second + d.second;
        if (valid(nc.first, nc.second)) {
            if (board[nc.first][nc.second] == active) {
                board[nc.first][nc.second] = FILL;
                flood(nc, active);
            }
        }
    }
}

int clusters;
vector<vector<bool>> used;
void getClusterSize(pair<int, int> coord, char active) {
    for (auto d : diffs) {
        pair<int, int> nc;
        nc.first = coord.first + d.first;
        nc.second = coord.second + d.second;
        if (valid(nc.first, nc.second)) {
            if (board[nc.first][nc.second] == active && 
                !used[nc.first][nc.second]) {
                used[nc.first][nc.second] = true;
                clusters++;
                getClusterSize(nc, active);
            }
        }
    }
}

void smushDown() {
    for (int j = 0; j < 10; j++) {
        for (int i = 11; i >= 0; i--) {
            if (board[i][j] == FILL) {
                bool shouldMove = false;
                for (int mover = i; mover >= 0; mover--) {
                    if (board[mover][j] != FILL) {
                        shouldMove = true;
                        break;
                    }
                }
                if (!shouldMove) continue;
                int offset = 0;
                for (int mover = i; mover >= 0; mover--) {
                    if (board[mover][j] != FILL) {
                        char temp = board[mover][j];
                        board[mover][j] = board[i - offset][j];
                        board[i - offset][j] = temp;
                        offset++;
                    }
                }
                i++;
            }
        }
    }
}

void smushLeft() {
    for (int j = 0; j < 10; j++) {
        if (board[11][j] == FILL) {
            bool shouldMove = false;
            for (int col = j; col < 10; col++) {
                if (board[11][col] != FILL) {
                    shouldMove = true;
                    break;
                }
            }
            if (!shouldMove) continue;
            int colMover;
            for (colMover = j; colMover < 9; colMover++)
                for (int i = 0; i < 12; i++)
                    board[i][colMover] = board[i][colMover+1];
            for (int i = 0; i < 12; i++)
                board[i][9] = FILL;
            j--;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    diffs = vector<pair<int, int>>();
    diffs.push_back(make_pair(0, -1));
    diffs.push_back(make_pair(-1, 0));
    diffs.push_back(make_pair(0, 1));
    diffs.push_back(make_pair(1, 0));

    int t; cin >> t;
    while (t != 0) {
        board = vector<vector<char>>(12, vector<char>(10));
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 10; j++)
                cin >> board[i][j];
        
        for (int i = 0; i < t; i++) {
            char row; cin >> row;
            int col; cin >> col;
            pair<int, int> coord = clickToIndex(row, col);

            if (!valid(coord.first, coord.second) || board[coord.first][coord.second] == FILL) continue;

            clusters = 1;
            used = vector<vector<bool>>(12, vector<bool>(10, false));
            used[coord.first][coord.second] = true;
            getClusterSize(coord, board[coord.first][coord.second]);
            if (clusters < 3) continue;

            char activeChar = board[coord.first][coord.second];
            board[coord.first][coord.second] = FILL;
            flood(coord,activeChar);

            smushDown();
            smushLeft();
        }

        int numCircles = 0;
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 10; j++)
                if (board[i][j] != FILL)
                    numCircles++;
        cout << numCircles << nl;
        cin >> t;
    }

    return 0;
}
