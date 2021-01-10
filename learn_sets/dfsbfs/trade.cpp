#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n, s; cin >> n >> s;
    vector<int> values(s+1);
    for (int i = 1; i <= s; i++) cin >> values[i];
    vector<vector<bool>> adjMat(s+1, vector<bool>(s+1, false));
    for (int i = 1; i <= n; i++) {
        int d, t; cin >> d >> t;
        for (int j = 1; j <= t; j++) {
            int tr; cin >> tr;
            adjMat[d][tr] = true;
        }
    }

    queue<int> bfs;
    vector<bool> visited(s+1, false);
    bfs.push(1);
    visited[1] = true;
    int maxV = values[1];
    while (!bfs.empty()) {
        int sandwich = bfs.front();
        bfs.pop();

        for (int i = 1; i <= s; i++) {
            if (visited[i]) continue;
            if (!adjMat[i][sandwich]) continue;
            bfs.push(i);
            visited[i] = true;
            maxV = max(values[i], maxV);
        }
    }
    cout << maxV << nl;
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
