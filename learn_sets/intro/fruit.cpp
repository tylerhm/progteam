#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

vector<int> takeVector(int n)
{
    vector<int> ret = vector<int>(n);
    for (int i = 0; i < n; i++) cin >> ret[i];
    return ret;
}

int main()
{
    int n; cin >> n;
    while (n--)
    {
        int d; cin >> d;
        vector<int> days = takeVector(d);
        
        int totalFruits = 0;
        int curOrder = 0, necOrder;
        for (int i = 0; i < d; i++)
        {
            totalFruits += days[i];
            necOrder = (totalFruits + i) / (i + 1);
            if (necOrder > curOrder)
                curOrder = necOrder;
        }
        int count = 0, maxCount = -oo;
        for (int f : days)
        {
            count += curOrder - f;
            if (count > maxCount)
                maxCount = count;
        }
        cout << curOrder << " " << maxCount << "\n";
    }

    return 0;
}
