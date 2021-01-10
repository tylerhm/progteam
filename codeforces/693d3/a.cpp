#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

int cuts(int w, int h) {
    if (w&1 && h&1) return 1;
    if (w&1)
        return 2*cuts(w, h/2);
    else if (h&1)
        return 2*cuts(w/2, h);
    else if (w > h)
        return 2*cuts(w/2, h);
    else
        return 2*cuts(w, h/2);
}

void solve(int t) {
    int w, h, n; cin >> w >> h >> n;
    cout << (cuts(w, h)>=n?"YES":"NO") << nl;
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
