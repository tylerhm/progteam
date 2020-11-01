#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int n, k;
int endCol, endRow;
vector<vector<int>> moves;

vector<pair<int, int>> knightsDiff = vector<pair<int, int>>();

bool isValid(pair<int, int> coord) { return (coord.first >= 0 && coord.first < n && coord.second >= 0 && coord.second < n); }

void printMoves()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (moves[i][j] == oo)
                cout << "0 ";
            else
                cout << moves[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

void findEnd(pair<int, int> start)
{
    queue<pair<int, int>> q = queue<pair<int, int>>();
    q.push(start);
    // populate knights moves
    while (!q.empty())
    {
        printMoves();
        pair<int, int> nextCoord = q.front();
        q.pop();

        for (pair<int, int> diff : knightsDiff)
        {
            pair<int, int> examined = make_pair(nextCoord.first + diff.first, nextCoord.second + diff.second);
            if (isValid(examined) && moves[examined.first][examined.second] > moves[nextCoord.first][nextCoord.second]+1)
            {
                moves[examined.first][examined.second] = moves[nextCoord.first][nextCoord.second]+1;
                q.push(examined);
            }
        }
        for (int i = -1; i <= 1; i+=2)
        {
            for (int j = 1; j <= k; j++)
            {
                pair<int, int> examined = make_pair(nextCoord.first + (i*j), nextCoord.second);
                if (isValid(examined) && moves[examined.first][examined.second] > moves[nextCoord.first][nextCoord.second] + 1)
                {
                    moves[examined.first][examined.second] = moves[nextCoord.first][nextCoord.second] + 1;
                    q.push(examined);
                }
            }
        }
        for (int i = -1; i <= 1; i+=2)
        {
            for (int j = 1; j <= k; j++)
            {
                pair<int, int> examined = make_pair(nextCoord.first, nextCoord.second + (i*j));
                if (isValid(examined) && moves[examined.first][examined.second] > moves[nextCoord.first][nextCoord.second] + 1)
                {
                    moves[examined.first][examined.second] = moves[nextCoord.first][nextCoord.second] + 1;
                    q.push(examined);
                }
            }
        }
    }
}

int main()
{
    knightsDiff.push_back(make_pair(1, 2));
    knightsDiff.push_back(make_pair(2, 1));
    knightsDiff.push_back(make_pair(2, -1));
    knightsDiff.push_back(make_pair(1, -2));
    knightsDiff.push_back(make_pair(-1, -2));
    knightsDiff.push_back(make_pair(-2, -1));
    knightsDiff.push_back(make_pair(-2, 1));
    knightsDiff.push_back(make_pair(-1, 2));


    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        cin >> n >> k;
        int startCol, startRow; cin >> startCol >> startRow;
        cin >> endCol >> endRow;
        startCol--; startRow--; endCol--; endRow--;

        moves = vector<vector<int>>(n, vector<int>(n, oo));
        moves[startCol][startRow] = 0;
        findEnd(make_pair(startCol, startRow));
        printMoves();
        cout << moves[endCol][endRow] << "\n";         
    }
    return 0;
}
