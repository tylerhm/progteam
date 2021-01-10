#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

template <class T>
pair<vector<bool>, vector<pair<T, vector<int>>>> dijkstra(
 const vector<vector<pair<int, T>>>& adj, int s) {
    using ST = pair<T, int>;
    priority_queue<ST, vector<ST>, greater<ST>> q;
    vector<pair<T, vector<int>>> dist(adj.size(), pair<T, vector<int>>());
    vector<bool> seen(adj.size());
    q.emplace(T{}, s);
    seen[s] = 1;
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (dist[u].first < d) continue;
        for (auto [v, w] : adj[u])
            if (!seen[v] || d + w < dist[v].first) {
                dist[v].second = dist[u].second;
                dist[v].second.push_back(v);
                q.emplace(dist[v].first = d + w, v);
                seen[v] = 1;
            }
    }
    return {seen, dist};
}

void tokenize(string const &str, vector<string> &out)
{
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(" ", end)) != std::string::npos)
    {
        end = str.find(" ", start);
        out.push_back(str.substr(start, end - start));
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    unordered_map<string, vector<string>> strAdjList;
    vector<vector<pair<int, int>>> adjList;
    unordered_map<string, int> nameToInd;
    unordered_map<int, string> indToName;

    string garb; getline(cin, garb);
    for (int i = 0; i < n; i++)
    {
        string line; getline(cin, line);

        vector<string> input;
        tokenize(line, input);

        for (string s : input)
            if (nameToInd.find(s) == nameToInd.end())
            {
                nameToInd[s] = nameToInd.size();
                indToName[indToName.size()] = s;
            }

        string name = input[0];

        vector<string> sub;
        for (int i = 1; i < input.size(); i++)
            sub.push_back(input[i]);

        strAdjList[name] = sub;
    }

    adjList = vector<vector<pair<int, int>>>(nameToInd.size(), vector<pair<int, int>>());

    for (auto map : strAdjList)
        for (string con : map.second)
        {
            adjList[nameToInd[map.first]].push_back(make_pair(nameToInd[con], 1));
            adjList[nameToInd[con]].push_back(make_pair(nameToInd[map.first], 1));
        }

    string start, end; cin >> start >> end;
    int s = nameToInd[start], e = nameToInd[end];

    auto ans = dijkstra(adjList, s);

    if (ans.first[e] == 0 || ans.second[e].second.size() == 0)
    {
        cout << "no route found\n";
        return 0;
    }

    cout << start << " ";
    for (int path : ans.second[e].second)
        cout << indToName[path] << " ";
    cout << "\n";

    return 0;
}
