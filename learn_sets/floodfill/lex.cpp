#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
//#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int n, m;
vector<vector<bool>> water;
int filled;

bool valid(int r, int c) { return (r >= 0 && r < n && c >= 0 && c < m && water[r][c]); }

void fill(int r, int c)
{
    if (valid(r, c-1))
    {
        filled++;
        water[r][c-1] = false;
        fill(r, c-1);
    }
    if (valid(r-1, c))
    {
        filled++;
        water[r-1][c] = false;
        fill(r-1, c);
    }
    if (valid(r, c+1))
    {
        filled++;
        water[r][c+1] = false;
        fill(r, c+1);
    }
    if (valid(r+1, c))
    {
        filled++;
        water[r+1][c] = false;
        fill(r+1, c);
    }
}

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        cin >> n >> m;
        water = vector<vector<bool>>(n, vector<bool>(m, false));
        int sr, sc;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char inp; cin >> inp;
                water[i][j] = (inp == '~');
                if (inp == 'X')
                {
                    sr = i;
                    sc = j;
                }
            }
        }
        filled = 1;
        fill(sr, sc);
        cout << filled*5 << "\n";
    }
    return 0;
}
