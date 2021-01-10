#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
#define MOD 1000000
int oo = -1^1<<31;
using namespace std;

vector<int> catalan(1001, 0);

void precalc() {
    for (int i = 0; i <= 1000; i++) {
        if (i == 0 || i == 1)
            catalan[i] = 1;
        else {
            ll sum = 0;
            ll l, r;
            for (int k = 1; k <= i; k++) {
                l = catalan[k-1] % MOD;
                r = catalan[i-k] % MOD;
                sum = (sum + (l * r) % MOD) % MOD;
            }
            catalan[i] = sum % MOD;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    precalc();

    int n; cin >> n;
    while (n != 0) {
        cout << catalan[n] << endl;
        cin >> n; 
    }

    return 0;
}
