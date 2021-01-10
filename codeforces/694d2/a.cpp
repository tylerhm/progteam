#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    ll sumS = 0, sumB = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sumS += arr[i];
        sumB += ceil((double)arr[i] / (double)x);
    }
    sumS = ceil((double)sumS / (double)x);
    cout << min(sumS, sumB) << " " << max(sumS, sumB) << nl;
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
