#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

#define OPEN '.'
#define OBST 'X'
#define LEFT '<'
#define UP '^'
#define RIGHT '>'
#define DOWN 'V'
#define FIRE 'F'

bool valid(vector<string> &map, int row, int col) {
    if (row < 0 || row >= map.size() ||
        col < 0 || col >= map[0].size())
        return false;
    return map[row][col] == OPEN || map[row][col] == FIRE;
}

bool isDrag(char c) {
    return (c == LEFT || c == UP || c == RIGHT || c == DOWN);
}

void flood(vector<string> &map, int row, int col, char dir, int type, int half) {
    int dx = 0, dy = 0;
    int lx = 0, ly = 0;
    int rx = 0, ry = 0;
    switch (dir) {
        case LEFT:
            dx = -1;
            ly = 1;
            ry = -1;
            break;
        case RIGHT:
            dx = 1;
            ly = -1;
            ry = 1;
            break;
        case UP:
            dy = -1;
            lx = -1;
            rx = 1;
            break;
        case DOWN:
            dy = 1;
            lx = 1;
            rx = -1;
            break;
    }

    int nRow = row + dy, nCol = col + dx;
    if (valid(map, nRow, nCol)) {
        map[nRow][nCol] = FIRE;
        flood(map, nRow, nCol, dir, 1, 0);
    }
    if (type == 1) return;

    int lRow = nRow + ly, lCol = nCol + lx;
    int rRow = nRow + ry, rCol = nCol + rx;
    if (valid(map, lRow, lCol) && (half == 0 || half == 1)) {
        map[lRow][lCol] = FIRE;
        flood(map, lRow, lCol, dir, 2, 1);
    }
    if (valid(map, rRow, rCol) && (half == 0 || half == 2)) {
        map[rRow][rCol] = FIRE;
        flood(map, rRow, rCol, dir, 2, 2);
    }
}

void solve(int t) {
    int rows, cols; cin >> rows >> cols;
    vector<string> map(rows);
    for (int i = 0; i < rows; i++) cin >> map[i];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (isDrag(map[i][j]))
                flood(map, i, j, map[i][j], 2, 0);

    cout << "Map #" << t << ":" << nl;
    for (int i = 0; i < rows; i++) cout << map[i] << nl;
    cout << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tt; cin >> tt;
    for (int t = 1; t <= tt; t++)
        solve(t);

    return 0;
}
