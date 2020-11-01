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
        int a; cin >> a;
        int b = sqrt(a);

        while (a % b != 0)
            b--;
        int w = a/b;

        cout << (b+w)*2 << "\n";
    }

    return 0;
}
