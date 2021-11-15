#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vector<int> marbles(n);
    for (auto &val: marbles) cin >> val;

    int sum = 0;
    for (int i : marbles) sum += i;

    if (marbles.size() == 1) {
        cout << 0 << ' ' << 0 << nl;
        return 0;
    }

    if (marbles.size() == 2) {
        cout << sum << ' ' << min(marbles[0], marbles[1]) << nl;
        return 0;
    }

    int moved = marbles[0] + marbles[n-1];
    vector<int> other(n-2);
    other[0] = marbles[0] + marbles[1];
    other[n-3] = marbles[n-1] + marbles[n-2];
    for (int i = 2; i < n-2; i++)
        other[i-1] = marbles[i];

    vector<int> dp(other.size());
    vector<bool> kept(other.size(), false);
    dp[0] = other[0];
    if (other[1] > other[0])
        kept[1] = true;
    else
        kept[0] = true;
    dp[1] = max(other[0], other[1]);
    for (int i = 2; i < other.size(); i++) {
        if (dp[i-2] + other[i] > dp[i-1])
            kept[i] = true;
        dp[i] = max(dp[i-2] + other[i], dp[i-1]);
    }

    int keptSum = dp[other.size()-1];

    for (int i = 0; i < other.size(); i++)
        if (!kept[i])
            moved+=other[i];

    cout << 2*sum << ' ' << moved << nl;

    

    return 0;
}
