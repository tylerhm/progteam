#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n; cin >> n;
    map<string, int> locs;
    vector<pair<int, vector<int>>> adjList;
    vector<int> inDegrees;
    int intermediates = 0;
    for (int i = 0; i < n; i++) {
        string u, v; cin >> u >> v;
        int id; cin >> id;
        if (!locs.count(u)) {
            locs[u] = locs.size() + intermediates;
            adjList.push_back({-1, vector<int>()});
            inDegrees.push_back(0);
        }
        if (!locs.count(v)) {
            locs[v] = locs.size() + intermediates;
            adjList.push_back({-1, vector<int>()});
            inDegrees.push_back(0);
        }
        adjList.push_back({id, vector<int>()});
        adjList[locs[u]].second.push_back(adjList.size()-1);
        inDegrees.push_back(1);
        adjList[adjList.size()-1].second.push_back(locs[v]);
        inDegrees[locs[v]]++;
        intermediates++;
    }

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> topo;
    for (int i = 0; i < adjList.size(); i++)
        if (inDegrees[i] == 0)
            topo.push({adjList[i].first, i});

    while (!topo.empty()) {
        auto node = topo.top();
        topo.pop();

        if (node.first != -1)
            cout << node.first << ' ';

        for (int next : adjList[node.second].second)
            if (--inDegrees[next] == 0)
                topo.push({adjList[next].first, next});
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
