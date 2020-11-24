#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int n;
vector<vector<vector<bool>>> mine, used;

bool valid(int x, int y, int z)
{
    return (x >= 0 && x < n &&
            y >= 0 && y < n &&
            z >= 0 && z < n &&
            mine[x][y][z] == 1 &&
            !used[x][y][z]);
}

int cleared;
vector<int> dx = {-1, 1, 0, 0, 0, 0},
            dy = {0, 0, -1, 1, 0, 0},
            dz = {0, 0, 0, 0, -1, 1};

void floodfill(int x, int y, int z)
{
    for (int d = 0; d < 6; d++) {
        int nx = x+dx[d], ny = y+dy[d], nz = z+dz[d];
        if (valid(nx, ny, nz)) {
            used[nx][ny][nz] = true;
            cleared++;
            floodfill(nx, ny, nz);
        }
    }
}

void clearUsed()
{
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            for (int z = 0; z < n; z++)
                used[x][y][z] = false;
}

int main()
{
    cin >> n;
    mine = vector<vector<vector<bool>>>(n, vector<vector<bool>>(n, vector<bool>(n)));
    used = vector<vector<vector<bool>>>(n, vector<vector<bool>>(n, vector<bool>(n)));
    int inp;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            for (int z = 0; z < n; z++) {
                cin >> inp;
                mine[x][y][z] = (inp == 1);
            }
        }
    }

    int sims; cin >> sims;
    //cout << sims << "\n";
    for (int i = 0; i < sims; i++)
    {
        int x, y, z; cin >> x >> y >> z;
        cleared = 0;
        if (mine[x][y][z] == true)
        {
            clearUsed();
            used[x][y][z] = true;
            cleared = 1;
            floodfill(x, y, z);
        }
        cout << "Simulation #" << (i+1) << ", volume cleared is " << cleared << " cubic feet.\n\n";
    }
    return 0;
}
