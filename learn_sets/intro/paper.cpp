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
        int e; cin >> e;
        int pages = 0;
        while (e--)
        {
            int s, p; cin >> s >> p;
            pages += s * ((p + 3) / 4);
        }
        cout << pages << "\n";
    }

    return 0;
}
