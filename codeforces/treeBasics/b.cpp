#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

vector<vector<int>> adjList;

pair<int, int> dfs(int cur, int par) {
    pair<int, int> ans(cur, 0);
    for (int child : adjList[cur]) {
        if (child == par) continue;
        auto next = dfs(child, cur);
        if (next.second > ans.second) ans = next;
    }
    ans.second++;
    return ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    adjList = vector<vector<int>>(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    auto farthest = dfs(0, 0);
    int diameter = dfs(farthest.first, farthest.first).second-1;
    
    // find all nodes that result in this diameter
    for (int i = 0; i < n; i++) {
        int d = dfs(i, i).second-1;
        cout << (d==diameter?diameter+1:diameter) << nl;
    }

    return 0;
}
