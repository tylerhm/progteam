#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

int n, m, r;

void update(vector<vector<int>> &ship, char dir, int x, int y) {
    if (dir == 'S') {
        int removed = 0;
        for (int i = n-1; i >= 0 && removed < r; i--) {
            if (ship[i][x] >= y) {
                removed++;
                ship[i][x]--;
            }
        }
    }
    else if (dir == 'N') {
        int removed = 0;
        for (int i = 0; i < n && removed < r; i++) {
            if (ship[i][x] >= y) {
                removed++;
                ship[i][x]--;
            }
        }
    }
    else if (dir == 'E') {
        int removed = 0;
        for (int i = m-1; i >= 0 && removed < r; i--) {
            if (ship[x][i] >= y) {
                removed++;
                ship[x][i]--;
            }
        }
    }
    else {
        int removed = 0;
        for (int i = 0; i < m && removed < r; i++) {
            if (ship[x][i] >= y) {
                removed++;
                ship[x][i]--;
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> n >> m;
    int k, p; cin >> r >> k >> p;

    vector<vector<int>> ship(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> ship[i][j];

    for (int i = 0; i < k; i++) {
        char dir; cin >> dir;
        int x, y; cin >> x >> y;
        x--;
        update(ship, dir, x, y);
    }

    ll maxSum = -1;
    for (int i = 0; i < n-p; i++) {
        ll sum = 0;
        for (int ii = i; ii < i+p; ii++)
            for (int jj = 0; jj < p; jj++)
                sum += ship[ii][jj];
        maxSum = max(maxSum, sum);
        for (int j = 0; j < m-p; j++) {
            for (int ii = i; ii < i+p; ii++) {
                sum -= ship[ii][j];
                sum += ship[ii][j+p];
            }
            maxSum = max(maxSum, sum);
        }
    }

    cout << maxSum << nl;

    return 0;
}
