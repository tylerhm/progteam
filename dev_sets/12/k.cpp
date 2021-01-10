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

    int n; cin >> n;
    vector<int> banks(n);
    for (int i = 0; i < n; i++) cin >> banks[i];

    int moves = 0;
    while (true) {
        int mn = INT_MAX, mi = -1;
        for (int i = 0; i < n; i++) {
            if (banks[i] < 0) {
                mn = min(mn, banks[i]);
                mi = i;
            }
        }
        if (mi == -1) break;

        int left = (mi-1)<0?n-1:(mi-1);
        int right = (mi+1)>=n?0:(mi+1);
        banks[mi] = -banks[mi];
        banks[left] -= banks[mi];
        banks[right] -= banks[mi];
        moves++;
    }

    cout << moves << nl;

    return 0;
}
