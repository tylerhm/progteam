#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n; cin >> n;
    while (n--)
    {
        int m; cin >> m;
        vector<vector<char>> slots = vector<vector<char>>(m, vector<char>());
        for (int i = 0; i < m; i++)
        {
            string possible; cin >> possible;
            for (char c : possible) slots[i].push_back(c);
        }
        
        int k; cin >> k;
        
        int totalPossible = 1;
        for (int i = 0; i < slots.size(); i++) totalPossible *= slots[i].size();

        k--;
        for (int i = 0; i < slots.size(); i++)
        {
            totalPossible /= slots[i].size();
            cout << slots[i][k / totalPossible];
            k -= (k / totalPossible) * totalPossible;
        }
        cout << "\n";
    }
    return 0;
}
