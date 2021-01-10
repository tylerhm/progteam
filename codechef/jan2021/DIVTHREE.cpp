#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n, k, d; cin >> n >> k >> d;
    ll numProbs = 0;
    for (int i = 0; i < n; i++) {
        int ai; cin >> ai;
        numProbs += ai;
    }
    int numConts = numProbs / k;
    cout << (numConts<=d?numConts:d) << nl;
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
