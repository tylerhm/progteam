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

    int x, y; cin >> x >> y;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        if ((x%k == 0 && (y-2)%k == 0) ||
            (y%k == 0 && (x-2)%k == 0) ||
            ((x-1)%k == 0 && (y-1)%k == 0) ||
            (x%k == 0 && (x-2)%k == 0 && (y-1)%k == 0) ||
            (y%k == 0 && (y-2)%k == 0 && (x-1)%k == 0))
            cout << "YES";
        else
            cout << "NO";
        cout << nl;
    }

    return 0;
}
