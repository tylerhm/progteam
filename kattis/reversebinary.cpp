#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n; cin >> n;
    stack<int> s = stack<int>();
    int ans = 0, mult = 1, base = 2;
    while (n > 0)
    {
        s.push(n%2);
        n /= 2;
    }
    while (!s.empty())
    {
        ans += mult * s.top();
        s.pop();
        mult *= base;
    }
    cout << ans << "\n";
    return 0;
}
