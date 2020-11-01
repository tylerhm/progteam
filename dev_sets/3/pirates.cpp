#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

vector<vector<int>> adjMatrix;
int n, lastTreasure;
ll firstHalf, secondHalf, final, minCost;

void permuteBury(int p, vector<bool>& usedBury, vector<int>& perm) {
    if (p == n) {
        secondHalf = 0;
        for (int i = 0; i < n - 1; i++)
            secondHalf += adjMatrix[n + perm[i]][n + perm[i + 1]];
        final = firstHalf + secondHalf + adjMatrix[lastTreasure][n + perm[0]];
        minCost = min(minCost, final);
    }
    for (int i = 0; i < n; i++) {
        if (!usedBury[i]) {
            usedBury[i] = true;
            perm[p] = i;
            permuteBury(p + 1, usedBury, perm);
            usedBury[i] = false;
        }
    }
}

void permuteTreasures(int p, vector<bool>& usedSearch, vector<int>& perm)
{
    if (p == n)
    {
        firstHalf = 0;
        for (int i = 0; i < n - 1; i++)
            firstHalf += adjMatrix[perm[i]][perm[i + 1]];

        lastTreasure = perm[n-1];
        vector<bool> usedBury = vector<bool>(n, false);
        vector<int> perm2 = vector<int>(n);
        permuteBury(0, usedBury, perm2);
    }

    for (int i = 0; i < n; i++)
    {
        if (!usedSearch[i])
        {
            usedSearch[i] = true;
            perm[p] = i;
            permuteTreasures(p + 1, usedSearch, perm);
            usedSearch[i] = false;
        }
    }
}


int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        cin >> n;
        adjMatrix = vector<vector<int>>(2*n, vector<int>(2*n));
        vector<bool> usedSearch = vector<bool>(n, false);
        vector<int> perm = vector<int>(n);
        minCost = oo;
        for (int i = 0; i < 2*n; i++)
            for (int j = 0; j < 2*n; j++)
                cin >> adjMatrix[i][j];
        permuteTreasures(0, usedSearch, perm);
        cout << minCost << "\n";
    }
    return 0;
}
