#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n_cases; cin >> n_cases;
    for (int iter = 1; iter <= n_cases; iter++)
    {
        ll l, rem = 0;
        string s; cin >> l >> s;
        while (rem < l && s[l - 1 - rem] == ')') rem++;
        if (rem <= l - rem) cout << "No\n";
        else cout << "Yes\n";
    }

    return 0;
}
