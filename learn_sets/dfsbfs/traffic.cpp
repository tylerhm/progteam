#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

bool fullBFS(vector<vector<int>>& adjList, int crash) {
    vector<bool> visited(adjList.size(), false);
    queue<int> bfs;
    int start = 0;
    if (crash == 0) {
        if (visited.size() == 1) return true;
        else start = 1;
    }
    bfs.push(start);
    visited[start] = true;
    int foundNodes = 1;
    while (!bfs.empty()) {
        int next = bfs.front();
        bfs.pop();

        for (int i : adjList[next]) {
            if (visited[i] || i == crash) continue;
            visited[i] = true;
            foundNodes++;
            bfs.push(i);
        }
    }
    return foundNodes >= adjList.size() - 1;
}

void solve(int t) {
    int k; cin >> k;
    vector<vector<int>> adjList(k);
    for (int i = 0; i < k; i++) {
        int l; cin >> l;
        adjList[i] = vector<int>(l);
        for (int j = 0; j < l; j++) {
            int c; cin >> c;
            adjList[i][j] = --c;
        }
    }

    cout << "City #" << t << nl;
    int c; cin >> c;
    for (int i = 0; i < c; i++) {
        int crash; cin >> crash;
        cout << (fullBFS(adjList, --crash)? "no": "yes") << nl;
    }
    cout << nl;
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
