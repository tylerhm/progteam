#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int n;
vector<int> edges;

int main()
{
    cin >> n;
    vector<vector<bool>> adjMatrix = vector<vector<bool>>(n, vector<bool>(n, false));
    edges = vector<int>(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cout << "? " << 1 << " " << i;
        cout.flush();
        cin >> edges[i];
    }
    
    for (int u = 1; u <= n; u++)
    {
        for (int v = u + 1; v <= n; v++)
        {
            cout << "? " << 2 << " " << u << " " << v;
            cout.flush();
            int uvc; cin >> uvc;

            if (edges[u] + edges[v] != uvc)
            {
                adjMatrix[u-1][v-1] = true;
                adjMatrix[v-1][u-1] = true;
            }
        }
    }

    cout << "!\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << (adjMatrix[i][j]? 1 : 0) << " ";
        cout << "\n";
    }
    cout.flush();
    return 0;
}
