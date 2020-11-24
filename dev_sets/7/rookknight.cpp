#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int n, k;
vector<bool> cols, rows;
vector<vector<bool>> board;
vector<vector<bool>> knightAttacked;
vector<pair<int, int>> knightDiffs;
int perm;

void printAns()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j])
            {
                cout << j+1 << " ";
                break;
            }
        }
    }
    cout << "\n";
}

void printBoard()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool safe(int row, int col)
{
    return (!(rows[row] || cols[col] || 
              knightAttacked[row][col]));
}

bool solve(int curRow)
{
    if (curRow >= n)
    {
        //printAns();
        if (++perm == k)
            return true;
    }

    for (int i = 0; i < n; i++)
    {
        if (safe(curRow, i))
        {
            board[curRow][i] = true;
            cols[i] = true;
            rows[curRow] = true;

            // register knight space as attacked
            vector<pair<int, int>> modified = vector<pair<int, int>>();
            int newRow, newCol;
            for (pair<int, int> d : knightDiffs)
            {
                newRow = curRow + d.first;
                newCol = i + d.second;
                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < n)
                {
                    if (!knightAttacked[newRow][newCol])
                    {
                        knightAttacked[newRow][newCol] = true;
                        modified.push_back(make_pair(newRow, newCol));
                    }
                }
            }

            if (solve(curRow + 1))
                return true;

            board[curRow][i] = false;
            cols[i] = false;
            rows[curRow] = false;

            // undo knights modifications
            for (pair<int, int> p : modified)
                knightAttacked[p.first][p.second] = false;
        }
    }
    return false;
}

int main()
{
    knightDiffs = vector<pair<int, int>>();
    knightDiffs.push_back(make_pair(1, 2));
    knightDiffs.push_back(make_pair(2, 1));
    knightDiffs.push_back(make_pair(2, -1));
    knightDiffs.push_back(make_pair(1, -2));
    knightDiffs.push_back(make_pair(-1, -2));
    knightDiffs.push_back(make_pair(-2, -1));
    knightDiffs.push_back(make_pair(-2, 1));
    knightDiffs.push_back(make_pair(-1, 2));

    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        cin >> n >> k;
        board = vector<vector<bool>>(n, vector<bool>(n, false));
        knightAttacked = vector<vector<bool>>(n, vector<bool>(n, false));
        cols = vector<bool>(n, false);
        rows = vector<bool>(n, false);

        perm = 0;
        solve(0);
        printAns();
    }
    return 0;
}
