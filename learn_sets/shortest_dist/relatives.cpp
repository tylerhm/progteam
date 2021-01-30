#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

void solve(int p, int r, int iter) {
    vector<vector<ll>> dist(p, vector<ll>(p, oo));
    map<string, int> nameToIndex;
    for (int i = 0; i < r; i++) {
        string u, v; cin >> u >> v;
        if (!nameToIndex.count(u))
            nameToIndex[u] = nameToIndex.size();
        if (!nameToIndex.count(v))
            nameToIndex[v] = nameToIndex.size();
        dist[nameToIndex[u]][nameToIndex[v]] = 1;
        dist[nameToIndex[v]][nameToIndex[u]] = 1;
    }
    for (int i = 0; i < p; i++) dist[i][i] = 0;
    for (int k = 0; k < p; k++)
        for (int i = 0; i < p; i++)
            for (int j = 0; j < p; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    ll maxSep = -oo;
    for (int i = 0; i < p; i++)
        for (int j = 0; j < p; j++)
            maxSep = max(maxSep, dist[i][j]);
    cout << "Network " << iter << ": ";
    if (maxSep == oo) cout << "DISCONNECTED";
    else cout << maxSep;
    cout << nl << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int p, r; cin >> p >> r;
    int iter = 1;
    while (p != 0 && r != 0) {
        solve(p, r, iter++);
        cin >> p >> r;
    }

    return 0;
}
