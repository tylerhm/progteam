#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    string inp; cin >> inp;
    int n = inp.size();

    // find letters influence on other palindromes
    int removals = 0;
    for (int i = 0; i < n; i++) {
        // odd size
        int lo = i-1, hi = i+1;
        while (lo >= 0 && hi < n) {
            if (inp[lo] != inp[hi] || inp[hi] == '-') break;
            removals++;
            inp[hi] = '-';
        }
        // even size
        lo = i, hi = i+1;
        while (lo >= 0 && hi < n) {
            if (inp[lo] != inp[hi] || inp[hi] == '-') break;
            removals++;
            inp[hi] = '-';
        }
    }

    cout << inp << nl;
    cout << removals << nl;
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
