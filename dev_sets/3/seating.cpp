#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

ll sequenced(int num)
{
    if (num == 0) return 1;
    if (num == 1) return 0;
    return (((2 * num) - 1) * sequenced(num - 1)) + sequenced(num - 2);
}

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        int c; cin >> c;
        cout << sequenced(c) << "\n";
    }
    return 0;
}
