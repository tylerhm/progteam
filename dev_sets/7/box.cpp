#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

#define BEN 'B'
#define OPEN '.'
#define WALL 'W'
#define BOX 'X'

int n, m; 
vector<vector<char>> mappy;
vector<vector<int>> dist;
vector<pair<int, int>> diffs;
int startCol, startRow;

void printDist()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[i][j] >= 0)
                cout << dist[i][j];
            else
                cout << 'X';
            cout << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool isValid(pair<int, int> p)
{
    return (p.first >= 0 && p.first < n &&
            p.second >= 0 && p.second < m &&
            dist[p.first][p.second] == -1 && 
            mappy[p.first][p.second] != WALL);
}

pair<int, int> findTele(pair<int, int> p)
{
    char teleNum = mappy[p.first][p.second];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (dist[i][j] == -1 && mappy[i][j] == teleNum) return make_pair(i, j);
    return make_pair(-1, -1);
}

int bfs()
{
    queue<pair<int, int>> q = queue<pair<int, int>>();
    dist[startCol][startRow] = 0;
    q.push(make_pair(startCol, startRow));

    while (!q.empty())
    {
        pair<int, int> curP = q.front();
        q.pop();

        if (mappy[curP.first][curP.second] == BOX) return dist[curP.first][curP.second];

        pair<int, int> moveTo;
        pair<int, int> teleTo;

        for (pair<int, int> d : diffs)
        {
            moveTo.first = curP.first + d.first;
            moveTo.second = curP.second + d.second;

            if (isValid(moveTo))
            {
                dist[moveTo.first][moveTo.second] = dist[curP.first][curP.second] + 1;
                q.push(moveTo);

                if (mappy[moveTo.first][moveTo.second] >= '0' &&
                    mappy[moveTo.first][moveTo.second] <= '9')
                {
                    teleTo = findTele(moveTo);
                    if (teleTo.first != -1)
                    {
                        dist[teleTo.first][teleTo.second] = dist[moveTo.first][moveTo.second];
                        q.push(teleTo);
                    }
                }
            }
        }
    }
    return -1;
}


int main()
{
    diffs = vector<pair<int, int>>();
    diffs.push_back(make_pair(0, -1));
    diffs.push_back(make_pair(-1, 0));
    diffs.push_back(make_pair(0, 1));
    diffs.push_back(make_pair(1, 0));
    cin >> n >> m;
    while (!(n == 0 && m == 0))
    {
        mappy = vector<vector<char>>(n, vector<char>(m));
        dist = vector<vector<int>>(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mappy[i][j];
                if (mappy[i][j] == BEN)
                {
                    startCol = i;
                    startRow = j;
                }
            }
        }
        cout << "He got the Box in " << bfs() << " steps!\n";
        //printDist();
        cin >> n >> m;
    }
    return 0;
}
