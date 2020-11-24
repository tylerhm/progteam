#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int knapSack(double maxV, vector<pair<int, double>>& options)
{
    vector<int> dp = vector<int>(maxV + 1, 0);

    for (int i = 0; i <= maxV; i++)
        for (int j = 0; j < options.size(); j++)
            if (options[j].second <= i)
                dp[i] = max(dp[i], dp[i - options[j].second] + options[j].first);

    return dp[maxV];
}

int main()
{
    int n; cin >> n;
    double m; cin >> m;
    while (n != 0) {
        m *= 100;
        vector<pair<int, double>> candies = vector<pair<int, double>>(n);
        for (int i = 0; i < n; i++) {
            int cal; cin >> cal;
            double price; cin >> price;
            price *= 100;
            candies[i] = make_pair(cal, price);
        }
        sort(candies);
        reverse(candies.begin(), candies.end());
        cout << knapSack(m, candies) << "\n";
        cin >> n;
        cin >> m;
    }
    return 0;
}
