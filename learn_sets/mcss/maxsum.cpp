#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int n;

int maxSum(vector<vector<int>>& arr)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int ii = i; ii < n; ii++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (ii != i)
                    sum += arr[ii][j]-arr[i][j];
                else
                    sum += arr[ii][j];
                if (sum > max)
                    max = sum;
                if (sum < 0)
                    sum = 0;
            }
        }
    }
    return max;
}

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--) {
        cin >> n;
        vector<vector<int>> partialCols = vector<vector<int>>(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int val; cin >> val;
                partialCols[i][j] += val;
                if (i != 0) partialCols[i][j] += partialCols[i - 1][j];
            }
        }
        cout << maxSum(partialCols) << "\n";
    }
    return 0;
}
