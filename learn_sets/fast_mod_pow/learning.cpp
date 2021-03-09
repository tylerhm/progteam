#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

#define MOD 1000000000

ll fastPow(ll b, ll p) {
    b%=MOD;
    cout << b << ' ' << p << endl;
    if (p==0)return 1;
    if (p==1)return b;
    if (p&1)return b*fastPow(b,p-1)%MOD;
    return fastPow(b*b%MOD,p/2);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll b, p; cin >> b >> p;
    while (b != 0) {
        cout << fastPow(b, p) << endl;
        cin >> b >> p;
    }

    return 0;
}
