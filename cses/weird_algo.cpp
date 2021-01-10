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
    
    while (n != 1) {
        cout << n << " ";
        if (n&1) n=n*3+1;
        else n/=2;
    }
    cout << n << "\n";

    return 0;
}
