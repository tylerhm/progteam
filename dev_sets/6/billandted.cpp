#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

template <class T>
pair<vector<bool>, vector<T>> dijkstra(
 const vector<vector<pair<int, T>>>& adj, int s) {
    using ST = pair<T, int>;
    priority_queue<ST, vector<ST>, greater<ST>> q;
    vector<T> dist(adj.size());
    vector<bool> seen(adj.size());
    q.emplace(T{}, s);
    seen[s] = 1;
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (dist[u] < d) continue;
        for (auto [v, w] : adj[u])
            if (!seen[v] || d + w < dist[v]) {
                q.emplace(dist[v] = d + w, v);
                seen[v] = 1;
            }
    }
    return {seen, dist};
}

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        int f; cin >> f;
        unordered_map<int, int> yearToNode = unordered_map<int, int>();
        int curNode = 0;
        vector<vector<pair<int, int>>> adjList = vector<vector<pair<int, int>>>();
        for (int i = 0; i < f; i++)
        {
            int year; cin >> year;
            yearToNode[year] = curNode++;
            vector<pair<int, int>> edges = vector<pair<int, int>>();
            for (int j = 0; j < f; j++)
            {
                int weight; cin >> weight;
                if (i == j)
                    continue;
                edges.push_back(make_pair(j, weight));
            }
            adjList.push_back(edges);
        }

        int startYear = 1989;
        int startIndex = yearToNode[startYear];
        auto dijkRes = dijkstra(adjList, startIndex);

        int findYear; cin >> findYear;
        int findIndex = yearToNode[findYear];

        cout << dijkRes.second[findIndex] << "\n";
    }
    return 0;
}
