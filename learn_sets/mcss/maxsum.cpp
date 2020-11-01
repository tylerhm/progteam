#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--) {
        int n; cin >> n;
        vector<vector<int>> mcss = vector<vector<int>>(n, vector<int>(n));
        int val;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> val;
                if (j == 0)
                    mcss[i][j] = val;
                else
                    mcss[i][j] = mcss[i][j-1] + val;
            }
        }

        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++)
                mcss[i][j] += mcss[i-1][j];

        int maxSum = -oo;
        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (mcss[i][j] > maxSum)
                    maxSum = mcss[i][j];
                for (int ii = 0; ii <= i; ii++)
                    for (int jj = 0; jj <= j; jj++)
                        if (mcss[i][j] - mcss[ii][jj] > maxSum)
                            maxSum = mcss[i][j] - mcss[ii][jj];
            }
        }
    cout << maxSum << "\n";
    }
    return 0;
}
