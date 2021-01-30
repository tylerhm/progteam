#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n; cin >> n;
    if (n > 1) cout << "Alice";
    else cout << "Bob";
    cout << endl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt; cin >> tt;
    for (int t = 0; t < tt; t++)
        solve(t);

    return 0;
}
