#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n, x; cin >> n >> x;
    vector<int> arr(n), stat(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        sum += val;
        arr[i] = val;
        stat[i] = val;
    }
    while (true) {
        bool stop = false;
        for (int i = 0; i < n; i++) {
            if (arr[i] % x == 0) {
                sum += stat[i];
                arr[i] /= x;
            }
            else {
                stop = true;
                break;
            }
        }
        if (stop) break;
    }
    cout << sum << nl;
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
