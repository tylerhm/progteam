#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

struct DSU {
    vector<int> s;
    DSU(int n) : s(n, -1) {}
    int find(int i) { return s[i] < 0 ? i : s[i] = find(s[i]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (s[a] > s[b]) swap(a, b);
        s[a] += s[b], s[b] = a;
        return true;
    }
    int size(int i) { return -s[find(i)]; }
    bool same(int a, int b) { return find(a) == find(b); }
};

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
    int p, r; cin >> p >> r;
    int iter = 1;
    while (!(p == 0 && r == 0))
    {
        cout << "Network " << iter++ << ": ";
        vector<vector<pair<int, int>>> connections = vector<vector<pair<int, int>>>(p, vector<pair<int, int>>());
        DSU dsu = DSU(p);
        unordered_map<string, int> people = unordered_map<string, int>();
        int personIndex = 0;
        for (int i = 0; i < r; i++)
        {
            string p1, p2; cin >> p1 >> p2;
            auto person1 = people.find(p1);
                if (person1 == people.end())
                    people[p1] = personIndex++;
            auto person2 = people.find(p2);
                if (person2 == people.end())
                    people[p2] = personIndex++;
            person1 = people.find(p1);
            person2 = people.find(p2);
            //cout << person1->second << " " << person2->second << endl;
            connections[person1->second].push_back(make_pair(person2->second, 1));
            connections[person2->second].push_back(make_pair(person1->second, 1));
            dsu.join(person1->second, person2->second);
        }
        bool connected = true;
        for (int i = 1; i < p; i++) {
            if (!dsu.same(0, i)) {
                cout << "DISCONNECTED" << "\n\n";
                connected = false;
                break;
            }
        }

        if (connected) {
            int maxdis = -1;
            for (int i = 0; i < p; i++) {
                pair<vector<bool>, vector<int>> res = dijkstra(connections, i);
                for (int j = 0; j < p; j++)
                    if (res.second[j] > maxdis)
                        maxdis = res.second[j];
            }
            cout << maxdis << "\n\n";
        }
        cin >> p >> r;
    }
    return 0;
}
