#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n_cases; cin >> n_cases;
    int iter = 1;
    while (n_cases--)
    {
        cout << "Target #" << iter++ << ": ";
        vector<int> sides = vector<int>(3);
        cin >> sides[0] >> sides[1] >> sides[2];
        sort(sides);
        if (sides[0]*sides[0] + sides[1]*sides[1] == sides[2]*sides[2])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
