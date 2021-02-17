#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

int iter = 0;

bool solve() {

    ll n;

    if (!(cin >> n))
        return false;

    map<ll, vector<ll>> rows, cols;

    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        cols[x].push_back(y);
        rows[y].push_back(x);
    }

    if (rows.size() == 1 || cols.size() == 1) {
        cout << 0 << nl;
        return true;
    }

    ll maxSize = 0;
    for (auto row : rows) {
        ll y = row.first;
        auto inRow = row.second;

        for (int i = 0; i < inRow.size() - 1; i++) {
            for (int j = i + 1; j < inRow.size(); j++) {
                ll side = inRow[j] - inRow[i];

                if (!count(all(cols[inRow[i]]), (y + side)) || !count(all(cols[inRow[j]]), (y + side))) continue;

                maxSize = max(maxSize, side);
            }
        }
    }

    cerr << "PRINTING ANS " << iter++ << nl;
    cout << maxSize << nl;

    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    while (solve());
    
    return 0;
}
