#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n; cin >> n;
    vector<vector<int>> adjList;
    map<string, int> people;
    map<int, string> back;
    for (int i = 0; i < n; i++) {
        string a, b, c; cin >> a >> b >> c;
        if (!people.count(a)) {
            back[people.size()] = a;
            people[a] = people.size();
            adjList.push_back(vector<int>(0));
        }
        if (!people.count(b)) {
            back[people.size()] = b;
            people[b] = people.size();
            adjList.push_back(vector<int>(0));
        }
        if (!people.count(c)) {
            back[people.size()] = c;
            people[c] = people.size();
            adjList.push_back(vector<int>(0));
        }
        int ai = people[a], bi = people[b], ci = people[c];
        adjList[ai].push_back(bi); adjList[ai].push_back(ci);
        adjList[bi].push_back(ai); adjList[bi].push_back(ci);
        adjList[ci].push_back(ai); adjList[ci].push_back(bi);
    }
    int ahmadI = -1;
    for (auto p : people) {
        if (p.first == "Ahmad") {
            ahmadI = p.second;
            break;
        }
    }
    cout << adjList.size() << nl;
    queue<int> bfs;
    vector<bool> visited(adjList.size(), false);
    bfs.push(ahmadI);
    visited[ahmadI] = true;
    int level = 0;
    while (true) {
        int size = bfs.size();
        vector<string> names;
        for (int i = 0; i < size; i++) {
            int u = bfs.front();
            bfs.pop();
            names.push_back(back[u]);
            for (int v : adjList[u]) {
                if (visited[v]) continue;
                bfs.push(v);
                visited[v] = true;
            }
        }
        sort(all(names));
        for (string s : names) cout << s << ' ' << level << nl;
        level++;
        if (bfs.empty()) break;
    }
    vector<string> undef;
    for (int i = 0; i < visited.size(); i++)
        if (!visited[i])
            undef.push_back(back[i]);
    sort(all(undef));
    for (string s : undef) cout << s << " undefined" << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tt; cin >> tt;
    for (int t = 0; t < tt; t++)
    solve(t);    

    return 0;
}
