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
        int n; cin >> n;
        vector<int> wagers = vector<int>(n);
        vector<double> prob = vector<double>(n);
        int total = 0;
        for (int i = 0; i < n; i++)
        { 
            cin >> wagers[i];
            total += wagers[i];
        }
        for (int i = 0; i < n; i++) cin >> prob[i];

        sort(wagers);
        sort(prob);

        double profit = 0;
        for (int i = 0; i < n; i++)
            profit += (wagers[i] * prob[i]) - (wagers[i] * (1 - prob[i]));
        
        printf("%.2f\n", profit);
    }
    return 0;
}
