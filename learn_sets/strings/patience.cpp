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
    vector<queue<int>> seqs(n);
    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        for (int j = 0; j < l; j++) {
            int v; cin >> v;
            seqs[i].push(v);
        }
    }

    while (true) {
        int mn = oo, midx = -1;
        for (int i = 0; i < n; i++) {
            if (seqs[i].empty()) continue;
            if (seqs[i].front() < mn) {
                mn = seqs[i].front();
                midx = i;
            }
        }
        if (midx == -1) break;
        seqs[midx].pop();
        cout << mn << ' ';
    }
    cout << nl;

    return 0;
}
