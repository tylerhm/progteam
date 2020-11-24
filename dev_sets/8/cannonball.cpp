#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

#define CANNON_RAD 50
#define LAUNCH_LAND 2
#define WALK_SPEED 5

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

vector<vector<pair<int, double>>> adjList;

double pairDist(pair<int, int>& p1, pair<int, int>& p2) {
    return sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}

int main()
{
    vector<pair<double, double>> nodes = vector<pair<double, double>>();
    vector<pair<double, double>> cannons = vector<pair<double, double>>();
    int x, y; cin >> x >> y;
    nodes.emplace_back(x, y);
    cin >> x >> y;
    nodes.emplace_back(x, y);

    // FROM 0 to 1

    // add all cannons to nodes
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        nodes.emplace_back(x, y);
        cannons.emplace_back(x, y);
    }

    // add all launchable (and helpful) locations to nodes
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;


        }
    }


    adjList = vector<vector<pair<int, double>>>();

    // connect to all nodes first (walking no cannons)
    for (int i = 0; i < nodes.size(); i++)
    {
        vector<pair<int, double>> list = vector<pair<int, double>>();
        for (int j = 0; j < nodes.size(); j++) {
            if (i == j) continue;
            list.emplace_back(j, pairDist(nodes[i], nodes[j]) / 5.0);
        }
    }

    return 0;
}
