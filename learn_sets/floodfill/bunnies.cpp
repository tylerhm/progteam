#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

bool foundC;
vector<vector<char>> cage;
vector<vector<bool>> valid;

struct Point
{
    int row;
    int col;
};

void findC(int row, int col)
{
    if (foundC)
        return;
    if (cage[row][col] == 'C')
    {
        foundC = true;
        return;
    }
    valid[row][col] = false;

    if (row - 1 >= 0 && valid[row - 1][col])
        findC(row - 1, col);
    if (col + 1 < cage[row].size() && valid[row][col + 1])
        findC(row, col + 1);
    if (row + 1 < cage.size() && valid[row + 1][col])
        findC(row + 1, col);
    if (col - 1 >= 0 && valid[row][col - 1])
        findC(row, col - 1);    
}

int main()
{
    int n; cin >> n;
    while (n--)
    {
        int r, c; cin >> r >> c;
        cage = vector<vector<char>>(r, vector<char>(c));
        valid = vector<vector<bool>>(r, vector<bool>(c, true));
        Point p;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> cage[i][j];
                if (cage[i][j] == 'P')
                {
                    p.row = i;
                    p.col = j;
                }
                else if (cage[i][j] == '#')
                    valid[i][j] = false;
            }
        }
        foundC = false;
        findC(p.row, p.col);
        if (foundC)
            cout << "yes";
        else
            cout << "no";
        cout << "\n";
    }

    return 0;
}
