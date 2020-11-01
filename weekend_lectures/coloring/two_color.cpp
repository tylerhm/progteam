#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

// pick a start node and color it black
// use a bfs to color all neighbors of this node white
// if a conflict ever arrises, answer is no

vector<vector<bool>> adjMatrix;
vector<int> colors;
vector<bool> visited;
int n;

bool isBipartite()
{
    colors = vector<int>(n, 0);
    visited = vector<bool>(n, false);
    queue<int> q = queue<int>();
    q.push(0);
    colors[0] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int i = 0; i < n; i++)
        {
            if (adjMatrix[node][i])
            {
                if (colors[i] != colors[node])
                {
                    if (colors[node] == 1)
                        colors[i] = 2;
                    else
                        colors[i] = 1;
                }
                else
                    return false;
                if (!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    return true;
}

int main()
{
    cin >> n;
    adjMatrix = vector<vector<bool>>(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int inp; cin >> inp;
            adjMatrix[i][j] = (inp == 0)? false: true;
        }
    cout << isBipartite() << "\n";
    return 0;
}
