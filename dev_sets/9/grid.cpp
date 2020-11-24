#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

int n, m;
vector<vector<pair<int, int>>> grid;

bool valid(int row, int col)
{
    return (row >= 0 && col >= 0 && row < n && col < m && grid[row][col].second == 0);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> n >> m;
    grid = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(m));
    for (int i = 0; i < n; i++)
    {
        string val; cin >> val;
        for (int j = 0; j < m; j++)
            grid[i][j] = make_pair(val[j]-'0', 0);
    }

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    while (!q.empty())
    {
        pair<int, int> curPoint = q.front();
        q.pop();

        if (curPoint.first == n-1 && curPoint.second == m-1)
        {
            cout << grid[curPoint.first][curPoint.second].second << "\n";
            return 0;
        }

        int toMove = grid[curPoint.first][curPoint.second].first;

        if (valid(curPoint.first, curPoint.second-toMove))
        {
            grid[curPoint.first][curPoint.second-toMove].second = grid[curPoint.first][curPoint.second].second+1;
            q.push(make_pair(curPoint.first, curPoint.second-toMove));
        }
        if (valid(curPoint.first-toMove, curPoint.second))
        {
            grid[curPoint.first-toMove][curPoint.second].second = grid[curPoint.first][curPoint.second].second+1;
            q.push(make_pair(curPoint.first-toMove, curPoint.second));
        }
        if (valid(curPoint.first, curPoint.second+toMove))
        {
            grid[curPoint.first][curPoint.second+toMove].second = grid[curPoint.first][curPoint.second].second+1;
            q.push(make_pair(curPoint.first, curPoint.second+toMove));
        }
        if (valid(curPoint.first+toMove, curPoint.second))
        {
            grid[curPoint.first+toMove][curPoint.second].second = grid[curPoint.first][curPoint.second].second+1;
            q.push(make_pair(curPoint.first+toMove, curPoint.second));
        }
    }

    cout << -1 << "\n";
    return 0;
}
