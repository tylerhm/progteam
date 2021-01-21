#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n; cin >> n;
    string b; cin >> b;
    
    string ans;
    int last = 0;
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == '1' && last != 2) {
            ans += '1';
            last = 2;
        }
        else if (b[i] == '0' && last != 1) {
            ans += '1';
            last = 1;
        }
        else if (b[i] == '0') {
            ans += '0';
            last = 0;
        }
        else if (b[i] == '1') {
            ans += '0';
            last = 1;
        }
    }
    cout << ans << nl;
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
