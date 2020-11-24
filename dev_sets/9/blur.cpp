#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

int n, m;
pair<int, int> wrappedCoord(int row, int col)
{
    int realRow = row;
    int realCol = col;
    if (row < 0)
        realRow = n + row;
    else if (row >= n)
        realRow = n - row;
    if (col < 0)
        realCol = m + col;
    else if (col >= m)
        realCol = m - col;
    
    return make_pair(realRow, realCol);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int b; cin >> m >> n >> b;

    vector<vector<ll>> image(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> image[i][j];

    // blur b times
    vector<vector<ll>> buffer(n, vector<ll>(m));
    ll av;
    for (int i = 0; i < b; i++)
    {
        // for each pixel
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // for each in 3x3
                av = 0;
                for (int di = -1; di <= 1; di++)
                {
                    for (int dj = -1; dj <= 1; dj++)
                    {
                        pair<int, int> coord = wrappedCoord(i+di, j+dj);
                        av += image[coord.first][coord.second];
                    }
                }
                buffer[i][j] = av * 9;
            }
        }
        image = buffer;
    }

    unordered_set<ll> occ;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            occ.insert(image[i][j]);

    cout << occ.size() << "\n";

    return 0;
}
