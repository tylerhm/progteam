#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define HOUR 60
#define LIMIT HOUR*10

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

bool solve() {
    int n; cin >> n;
    if (n == 0) return false;

    vector<vector<pair<int, int>>> adjList(n);
    

    int h; cin >> h;
    vector<int> hotels(h);
    map<int, int> cityToHotel;

    rep(i, 0, h) {
        int c; cin >> c; c--;
        hotels[i] = c;
        cityToHotel[c] = i;
    }

    if (!cityToHotel[0]) {
        hotels.push_back(0);
        cityToHotel[0] = cityToHotel.size();
    }

    if (!cityToHotel[n-1]) {
        hotels.push_back(n-1);
        cityToHotel[n-1] = cityToHotel.size();
    }

    vector<vector<pii>> adjHotels(hotels.size());

    int m; cin >> m;
    rep(i, 0, m) {
        int a, b, t; cin >> a >> b >> t; a--; b--;
        adjList[a].emplace_back(b, t);
        adjList[b].emplace_back(a, t);
    }

    for (int u : hotels) {
        auto res = dijkstra(adjList, u);
        for (int v : hotels)
            if (u != v && res.first[v] && res.second[v] <= LIMIT)
                adjHotels[cityToHotel[u]].emplace_back(cityToHotel[v], 1);
    }

    auto res = dijkstra(adjHotels, cityToHotel[0]);
    
    cout << (res.first[cityToHotel[n-1]] ? res.second[cityToHotel[n-1]] : -1) << endl;

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    while(solve());

    return 0;    
}
