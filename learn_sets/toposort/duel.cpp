#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int n, int m) {
    vector<vector<int>> adjList(n);
    vector<int> ind(n, 0);
    for (int i = 0; i < m; i++) {
        int d, u; cin >> d >> u;
        d--; u--;
        adjList[d].push_back(u);
        ind[u]++;
    }

    queue<int> topo;
    for (int i = 0; i < n; i++) {
        if (ind[i] == 0)
            topo.push(i);
    }

    int found = topo.size(), ways = found;
    while (!topo.empty()) {

        int s = topo.size(), additions = 0;
        for (int i = 0; i < s; i++) {
            int cur = topo.front();
            topo.pop();

            for (int next : adjList[cur]) {
                if (--ind[next] == 0) {
                    topo.push(next);
                    found++;
                    additions++;
                }
            }
        }
        if (additions > 0) ways *= additions;
    }
    cout << (found==n?(ways==1?1:2):0) << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m; cin >> n >> m;
    while (n != 0 && m != 0) {
        solve(n, m);
        cin >> n >> m;
    }

    return 0;
}
