#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n; cin >> n;
    vector<int> ns(n);
    for (int i = 0; i < n; i++) cin >> ns[i];
    int m; cin >> m;
    vector<int> ms(m);
    for (int i = 0; i < m; i++) cin >> ms[i];

    int maxSizeN = 0;
    int curSizeN = 0;
    for (int i = 0; i < n; i++) {
        curSizeN += ns[i];
        if (curSizeN > maxSizeN) maxSizeN = curSizeN;
    }
    int maxSizeM = 0;
    int curSizeM = 0;
    for (int i = 0; i < m; i++) {
        curSizeM += ms[i];
        if (curSizeM > maxSizeM) maxSizeM = curSizeM;
    }
    cout << maxSizeN + maxSizeM << nl;
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
