#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    int last; cin >> last;
    ll total = 0;
    for (int i = 0; i < n-1; i++) {
        int val; cin >> val;
        if (val > last) {
            last = val;
            continue;
        }
        last++;
        int added = last - val;
        total += added;
    }
    cout << total << "\n";

    return 0;
}
