#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n; cin >> n;
    while (n != 0) {
        int maxSum = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int val; cin >> val;
            sum += val;
            if (sum > maxSum) maxSum = sum;
            if (sum < 0) sum = 0;
        }
        cout << maxSum << "\n";
        cin >> n;
    }
    return 0;
}
