#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {

}

int getBombs(vector<vector<int>> &board, int i, int j, int n, int m) {
    int bombs = 0;
    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if ((k == 0 && l == 0) ||
                i + k < 0 || i + k >= n ||
                j + l < 0 || j + l >= m) continue;
            else if (board[i+k][j+l] == -1)
                bombs++;
        }
    }
    return bombs;
}

int getNeighbors(vector<vector<int>> &board, int i, int j, int n, int m) {
    int neighbors = 0;
    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if ((k == 0 && l == 0) ||
                i + k < 0 || i + k >= n ||
                j + l < 0 || j + l >= m) continue;
            else if (board[i+k][j+l] != -1)
                neighbors++;
        }
    }
    return neighbors;
}

void takeBoard(vector<vector<int>> &board, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char inp; cin >> inp;
            if (inp == 'X') {
                board[i][j] = -1;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if ((k == 0 && l == 0) ||
                            i + k < 0 || i + k >= n ||
                            j + l < 0 || j + l >= m) continue;
                        else if (board[i+k][j+l] != -1)
                            board[i+k][j+l]++;
                    }
                }
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<vector<int>> b(n, vector<int>(m, 0));

    // a
    takeBoard(a, n, m);
    takeBoard(b, n, m);


    ll aSum = 0, bSum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            aSum += a[i][j]==-1?0:a[i][j];
            bSum += b[i][j]==-1?0:b[i][j];
        }
    }
    
    ll changed = 0;
    ll maxChanged = n*m/2;
    while (aSum - bSum != 0) {

        if (changed == maxChanged) {
            cout << -1 << nl;
            return 0;
        }

        int bestBSum = bSum;
        int br = -1, bc = -1;
        bool bestPlace = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int emptyNeighbors = getNeighbors(b, i, j, n, m);
                int bombNeighbors = getBombs(b, i, j, n, m);
                int impact;
                if (b[i][j] != -1)  { // place bomb
                    impact = emptyNeighbors-bombNeighbors;
                    ll newSum = bSum + impact;
                    if (abs(aSum - newSum) < abs(aSum - bestBSum)) {
                        bestBSum = newSum;
                        br = i, bc = j;
                        bestPlace = true;
                    }
                }
                else if (b[i][j] == -1) { // remove bomb
                    impact = bombNeighbors-emptyNeighbors;
                    ll newSum = bSum + impact;
                    if (abs(aSum - newSum) < abs(aSum - bestBSum)) {
                        bestBSum = newSum;
                        br = i, bc = j;
                        bestPlace = false;
                    }
                }
            }
        }

        if (br == -1 && bc == -1) {
            cout << -1 << nl;
            return 0;
        }

        b[br][bc] = bestPlace?-1:getBombs(b, br, bc, n, m);
        bSum = bestBSum;
        changed++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (b[i][j]==-1?'X':'.');
        }
        cout << nl;
    }


    return 0;
}
