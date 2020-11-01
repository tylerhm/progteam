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
        string moves; cin >> moves;

        int maxDepth = oo, localDepth = 0;
        for (char c : moves)
        {
            if (c == 'v') localDepth--;
            else if (c == '^') localDepth++;
            if (localDepth < maxDepth)
                maxDepth = localDepth;
        }
        if (maxDepth < 0)
            cout << -maxDepth << "\n";
        else
            cout << 0 << "\n";
    }

    return 0;
}
