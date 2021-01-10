#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n_cases; cin >> n_cases;
    for (int iter = 1; iter <= n_cases; iter++)
    {
        int n, m; cin >> n >> m;
        vector<bool> usedRows(n, false), usedCols(n, false), solved(n, false);
        int numSolved = 0;
        for (int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            if (x == y) {
                solved[x-1] = true;
                numSolved++;
            }
            usedRows[y-1] = true;
            usedCols[x-1] = true;
        }

        while (numSolved < m) {
            for (int i = 0; i < n; i++) {
                if (solved[i]) continue;
                if (usedCols[i] && usedRows[i]) continue;
                if (usedCols[i])
            }
        }
    }

    return 0;
}
