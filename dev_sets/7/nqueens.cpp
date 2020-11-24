#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int n;
vector<bool> cols, rows, diag1, diag2;
vector<vector<bool>> board;

void printAns()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //cout << board[i][j] << " ";
            if (board[i][j])
            {
                cout << j+1 << " ";
                break;
            }
        }
        //cout << "\n";
    }
    cout << "\n";
}

bool safe(int row, int col)
{
    return (!(cols[col] || rows[row] ||
              diag1[col - row + (n - 1)] ||
              diag2[col + row]));
}

bool solve(int curRow)
{
    if (curRow >= n) return true;

    for (int i = 0; i < n; i++)
    {
        if (safe(curRow, i))
        {
            int d1 = i - curRow + n - 1;
            int d2 = i + curRow;
            board[curRow][i] = true;
            cols[i] = true;
            rows[curRow] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            if (solve(curRow + 1))
                return true;

            board[curRow][i] = false;
            cols[i] = false;
            rows[curRow] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
    return false;
}

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        cin >> n;
        board = vector<vector<bool>>(n, vector<bool>(n, false));
        cols = vector<bool>(n, false);
        rows = vector<bool>(n, false);
        diag1 = vector<bool>(2*n-1, false);
        diag2 = vector<bool>(2*n-1, false);

        solve(0);
        printAns();
    }
    return 0;
}
