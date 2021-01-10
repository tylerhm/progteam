#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n; cin >> n;
    ll sum = 0;
    for (int i = 0; i < n-1; i++) {
        ll v; cin >> v;
        sum += v;
    }

    cout << (n*(n+1)/2) - sum << "\n";

    return 0;
}
