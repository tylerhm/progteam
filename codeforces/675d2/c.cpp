#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
#define MOD 1000000007
int oo = -1^1<<31;
using namespace std;

int sum;

bool on(int mask, int pos) { return (mask & (1 << pos)) > 0; }

void subsets(string num, int size)
{
    sum = 0;
    ll res, mul;
    for (int mask = 1; mask < (1 << size)-1; mask++)
    {
        res = 0, mul = 1;
        for (int k = size-1; k >= 0; k--) {
            if (on(mask, k)) {
                sum = (sum % MOD + ((num[k]-'0') * mul) % MOD) % MOD;
                mul *= 10;
            }
        }
    }
}

int main()
{
    string num; cin >> num;
    subsets(num, num.size());
    cout << sum << "\n";

    return 0;
}
