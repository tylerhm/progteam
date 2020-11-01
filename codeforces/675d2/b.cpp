#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        int n, m; cin >> n >> m;
        vector<vector<int>> matrix = vector<vector<int>>(n, vector<int>(m));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) 
                cin >> matrix[i][j];

        vector<vector<bool>> used = vector<vector<bool>>(n, vector<bool>(m, false));
        ll cost = 0;

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (used[y][x]) continue;
                vector<int> pieces = vector<int>();
                int otherX = m - 1 - x;
                int otherY = n - 1 - y;

                int xs[] = {x, x, otherX, otherX}, ys[] = {y, otherY, y, otherY};
                for (int combo = 0; combo < 4; combo++) {
                    int newX = xs[combo], newY = ys[combo];
                    if (!used[newY][newX]) {
                        pieces.push_back(matrix[newY][newX]);
                        used[newY][newX] = true;
                    }
                }

                sort(pieces);
                int middle = pieces[pieces.size() / 2];
                for (int i : pieces) cost += abs(i - middle);
            }
        }
        cout << cost << "\n";
    }
    return 0;
}
