#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int gcd(int a, int b)
{
    return (b > 0) ? gcd(b, a % b) : a;
}

int main()
{
    cout << gcd(650, 550) << "\n";
    return 0;
}
