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
    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        pairs[i] = make_pair(x, y);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int num = abs(pairs[j].second - pairs[i].second);
            int den = abs(pairs[j].first - pairs[i].first);
            if (num <= den) count++;
        }
    }

    cout << count << nl;

    return 0;
}
