#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {

}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int a, b; cin >> a >> b;
    
    int m = INT_MIN;

    int lastDig;
    int sum = 0;
    while (a > 0) {
        lastDig = a % 10;
        sum+=lastDig;
        a/=10;
    }
    m = max(sum, m);
    sum = 0;
    while (b > 0) {
        lastDig = b % 10;
        sum+=lastDig;
        b/=10;
    }
    m = max(sum, m);

    cout << m << nl;

    return 0;
}
