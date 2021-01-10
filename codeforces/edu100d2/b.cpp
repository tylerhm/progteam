#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n; cin >> n;
    // ok crazy idea, but use powers of 2?
    // they'll never NOT be divisible by each other
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        // round val to nearest pow of 2
        cout << (1<<(int)log2(val)) << " ";
    }
    cout << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tt; cin >> tt;
    for (int t = 1; t <= tt; t++)
        solve(t);

    return 0;
}
