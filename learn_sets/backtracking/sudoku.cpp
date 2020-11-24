#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

vector<vector<int>> board;
vector<vector<bool>> usedRowVal, usedColVal;
vector<vector<vector<bool>>> usedSubVal;

bool solveBoard(int row, int col)
{
    if (col == 9) return solveBoard(row + 1, 0);
    else if (row == 9) return true;

    if (board[row][col] != 0) return solveBoard(row, col + 1);

    // try every number
    for (int i = 1; i < 10; i++)
    {
        if (!(usedRowVal[row][i] || usedColVal[col][i] || usedSubVal[row/3][col/3][i]))
        {
            board[row][col] = i;
            usedRowVal[row][i] = true;
            usedColVal[col][i] = true;
            usedSubVal[row/3][col/3][i] = true;
            if (solveBoard(row, col + 1)) return true;
            usedRowVal[row][i] = false;
            usedColVal[col][i] = false;
            usedSubVal[row/3][col/3][i] = false;
        }
    }
    board[row][col] = 0;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_cases; cin >> n_cases;
    for (int iter = 1; iter <= n_cases; iter++)
    {
        board = vector<vector<int>>(9, vector<int>(9));
        usedRowVal = vector<vector<bool>>(9+1, vector<bool>(9+1, false));
        usedColVal = vector<vector<bool>>(9+1, vector<bool>(9+1, false));
        usedSubVal = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(9+1, false)));
        int val;
        bool invalidStart = false;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> val;
                board[i][j] = val;
                if (val == 0) continue;
                if (usedRowVal[i][val] || usedColVal[j][val] || usedSubVal[i/3][j/3][val]) invalidStart = true;
                board[i][j] = val;
                usedRowVal[i][val] = true;
                usedColVal[j][val] = true;
                usedSubVal[i/3][j/3][val] = true;
            }
        }
        
        cout << "Test case " << iter << ":\n";
        if (!invalidStart && solveBoard(0, 0))
        {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    cout << board[i][j];
                    if (j != 8) cout << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }
        else
            cout << "No solution possible.\n\n";
        
    }
    return 0;
}
