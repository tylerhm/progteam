#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

void solve(int t) {

}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int a, b, c, n; cin >> a >> b >> c >> n;
    if (a+b+c >= n && a >= 1 && b >= 1 && c >= 1 && n >= 3) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
