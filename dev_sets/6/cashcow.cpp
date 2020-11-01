#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

#define FILL_CHAR ' '

vector<pair<int, int>> diffs;
pair<int, int> clickToIndex(char row, int col) { return make_pair(abs(col-12), row-'a'); }
vector<vector<char>> board;

void floodfill(pair<int, int> coord, char active)
{
    for (pair<int, int> diff : diffs)
    {
        pair<int, int> newCoord;
        newCoord.first = coord.first + diff.first;
        newCoord.second = coord.second + diff.second;
        if (newCoord.first >= 0 && newCoord.first < 12 &&
            newCoord.second >= 0 && newCoord.second < 10)
        {
            if (board[newCoord.first][newCoord.second] == active)
            {
                board[newCoord.first][newCoord.second] = FILL_CHAR;
                floodfill(newCoord, active);
            }
        }
    }
}

int clusters;
vector<vector<bool>> used;
void getClusterSize(pair<int, int> coord, char active)
{
    for (pair<int, int> diff : diffs)
    {
        pair<int, int> newCoord;
        newCoord.first = coord.first + diff.first;
        newCoord.second = coord.second + diff.second;
        if (newCoord.first >= 0 && newCoord.first < 12 &&
            newCoord.second >= 0 && newCoord.second < 10)
        {
            if (board[newCoord.first][newCoord.second] == active && 
                !used[newCoord.first][newCoord.second])
            {
                used[newCoord.first][newCoord.second] = true;
                clusters++;
                getClusterSize(newCoord, active);
            }
        }
    }
}

void smushDown()
{
    for (int j = 0; j < 10; j++)
    {
        // go bottom to top, finding gaps
        for (int i = 11; i >= 0; i--)
        {
            if (board[i][j] == FILL_CHAR)
            {
                // move everything above it down
                // check to make sure its not only fill above
                bool shouldMove = false;
                for (int mover = i; mover >= 0; mover--)
                {
                    if (board[mover][j] != FILL_CHAR)
                    {
                        shouldMove = true;
                        break;
                    }
                }
                if (!shouldMove)
                    continue;
                int offset = 0;
                for (int mover = i; mover >= 0; mover--)
                {
                    if (board[mover][j] != FILL_CHAR)
                    {
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

void smushLeft()
{
    // find gap
    for (int j = 0; j < 10; j++)
    {
        // gap found
        if (board[11][j] == FILL_CHAR)
        {
            // verify its a closable gap
            bool shouldMove = false;
            for (int col = j; col < 10; col++)
            {
                if (board[11][col] != FILL_CHAR)
                {
                    shouldMove = true;
                    break;
                }
            }
            if (!shouldMove)
                continue;
            // move everything else over
            int colMover;
            for (colMover = j; colMover < 9; colMover++)
                for (int i = 0; i < 12; i++)
                    board[i][colMover] = board[i][colMover+1];
            for (int i = 0; i < 12; i++)
                board[i][9] = FILL_CHAR;
            j--;
        }
    }
}

void printBoard()
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << board[i][j];
        cout << "\n";
    }
    cout << "----------\n";
}

int main()
{
    diffs = vector<pair<int, int>>();
    diffs.push_back(make_pair(0, -1));
    diffs.push_back(make_pair(-1, 0));
    diffs.push_back(make_pair(0, 1));
    diffs.push_back(make_pair(1, 0));

    int t; cin >> t;
    while (t != 0)
    {
        board = vector<vector<char>>(12, vector<char>(10));
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 10; j++)
                cin >> board[i][j];
        
        // move cycle
        for (int i = 0; i < t; i++)
        {
            char row; cin >> row;
            int col; cin >> col;
            pair<int, int> coord = clickToIndex(row, col);
            cout << "SELECTED MOVE " << coord.first << " " << coord.second << "\n";

            cout << "BEFORE MOVE\n";
            printBoard();

            // initial non pop edge cases
            // click empty
            if (coord.first < 0 || coord.first > 12 ||
                coord.second < 0 || coord.second > 10 ||
                board[coord.first][coord.second] == FILL_CHAR)
                continue;

            // check for at least 3 combo
            clusters = 1;
            used = vector<vector<bool>>(12, vector<bool>(10, false));
            used[coord.first][coord.second] = true;
            getClusterSize(coord, board[coord.first][coord.second]);
            if (clusters < 3)
                continue;

            // floodfill time
            char activeChar = board[coord.first][coord.second];
            board[coord.first][coord.second] = FILL_CHAR;
            floodfill(coord, activeChar);

            cout << "AFTER FILL\n";
            printBoard();

            // fix floaters
            smushDown();
            // fix stragglers
            smushLeft();

            cout << "AFTER MOVE\n";
            printBoard();
        }

        // count numcircles left
        int numCircles = 0;
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 10; j++)
                if (board[i][j] != FILL_CHAR)
                    numCircles++;
        cout << numCircles << "\n";

        cin >> t;   
    }
    return 0;
}
