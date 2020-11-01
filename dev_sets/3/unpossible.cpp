#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

vector<vector<bool>> adjMatrix;
int n;

void topSort()
{
    for (int v = 0; v < n; v++)
    {
        int nv = 0;
        while (nv < n)
        {
            bool found = true;
            for (int r = 0; r < n; r++)
            {
                if (adjMatrix[r][nv])
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                cout << nv+1 << "\n";
                fill(adjMatrix[nv], false);
                adjMatrix[nv][nv] = true;
                break;
            }
            else
                nv++;
        }
    }
}

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        cin >> n;
        adjMatrix = vector<vector<bool>>(n, vector<bool>(n, false));
        for (int i = 0; i < n-1; i++)
        {
            int f, s; cin >> f >> s;
            adjMatrix[f-1][s-1] = true;
        }
        topSort();
    }
    return 0;
}
