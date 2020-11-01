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
        vector<int> districts = vector<int>(n);
        for (int i = 0; i < n; i++) cin >> districts[i];
        int d0 = districts[0];
        bool valid = false;
        for (int i = 0; i < n; i++)
        {
            if (districts[i] != d0)
            {
                cout << "YES\n";
                valid = true;
                break;
            }
        }
        if (!valid)
        {
            cout << "NO\n";
            continue;
        }            
        
        // find all districts that are not the same as d0 and connect
        vector<int> toBeConnected = vector<int>();
        int diff = -1;
        for (int i = 1; i < n; i++)
        {
            if (districts[i] != d0)
            {
                cout << 1 << " " << (i + 1) << "\n";
                diff = i;
            }
            else
                toBeConnected.push_back(i);
        }

        for (int i = 0; i < toBeConnected.size(); i++)
            cout << (diff + 1) << " " << (toBeConnected[i] + 1) << "\n";
    }
    return 0;
}
