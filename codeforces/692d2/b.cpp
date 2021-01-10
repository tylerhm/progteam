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
        ll n; cin >> n;
        while (true) {
            ll copy = n;
            bool valid = true;
            while (copy > 0) {
                int dig = copy % 10;
                copy /= 10;

                if (dig != 0 && n % dig) {
                    valid = false;
                    break;
                }
            }
            if (valid) break;
            n++;
        }
        cout << n << "\n";
    }

    return 0;
}
