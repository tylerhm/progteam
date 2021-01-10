#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

vector<vector<int>> data;

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
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m; cin >> n >> m;
    while (n != 0 && m != 0) {

        vector<vector<int>> data(n, vector<int>(m));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> data[i][j];

        

        cin >> n >> m;
    }
    return 0;
}
