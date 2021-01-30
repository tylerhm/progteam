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
    vector<vector<int>> dist(n, vector<int>(n));

    for (auto& arr : dist)
        for (auto& val : arr)
            cin >> val;
    
    for (int i = 0; i < n; i++) dist[i][i] = 0;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    int p; cin >> p;
    for (int i = 0; i < p; i++) {
        int s, d, l; cin >> s >> d >> l;
        int ans = 0;
        for (int m = 1; m < n; m += 2)
            if (134 + dist[s][m] + dist[m][d] <= l)
                ans++;
        cout << ans << nl;
    }

    return 0;
}
