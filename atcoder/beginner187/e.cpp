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
    vector<vector<int>> adjList(n);
    vector<int> ai(n), bi(n);
    vector<ll> values(n, 0);
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adjList[--a].push_back(--b);
        adjList[b].push_back(a);
        ai[i] = a; bi[i] = b;
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        ll t, e, x; cin >> t >> e >> x;
        e--;
        int start, cantuse;
        if (t&1) {
            start = ai[e];
            cantuse = bi[e];
        }
        else {
            start = bi[e];
            cantuse = ai[e];
        }

        vector<int> visited(n, false);
        queue<int> bfs;
        bfs.push(start);
        visited[start] = true;
        visited[cantuse] = true;
        while (!bfs.empty()) {
            int t = bfs.front();
            bfs.pop();

            values[t] += x;

            for (int i : adjList[t]) {
                if (visited[i]) continue;
                visited[i] = true;
                bfs.push(i);
            }
        }
    }

    for (int i : values) cout << i << nl;
    

    return 0;
}
