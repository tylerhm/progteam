#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

int w, h;
vector<string> board;
int ans;

bool checkReady(int row, int col) {
    // find adjacent tiles that have a number
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int maxSquares
    for (int i = 0; i < 4; i++) {
        int nc = col + dx[i];
        int nr = row + dy[i];
        if (!(nc >= 0 && nc < w && nr >= 0 && nr < h)) continue;
    }
}

bool backtrack(int row, int col, int tiles) {
    if (row == h && col == w) {
       ans = tiles;
       return true; 
    } 
    if (col == w) row++;

    // empty, try all options
    if (board[row][col] == '.') {
        if (backtrack(row, col + 1, tiles))
            return true;
        
        // check if this location is available for placement
        bool readyToPlace = checkReady(row, col);
        for (int i = 0; i < 4; i++) {

        }
    }
}

bool placeDefined()

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> w >> h;
    board = vector<string>(h);
    for (int i = 0; i < h; i++) cin >> board[i];


    return 0;
}
