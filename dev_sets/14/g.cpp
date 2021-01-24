#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

namespace SCCKosaraju {
  vector<vector<int>> adj, radj;
  vector<int> todo, comp;
  vector<bool> vis;
  void dfs1(int x) {
    vis[x] = 1;
    for (int y : adj[x])
      if (!vis[y]) dfs1(y);
    todo.push_back(x);
  }
  void dfs2(int x, int i) {
    comp[x] = i;
    for (int y : radj[x])
      if (comp[y] == -1) dfs2(y, i);
  }
  vector<int> scc(vector<vector<int>>& _adj) {
    adj = _adj;
    int time = 0, n = adj.size();
    comp.resize(n, -1), radj.resize(n), vis.resize(n);
    for (int x = 0; x < n; x++)
      for (int y : adj[x]) radj[y].push_back(x);
    for (int x = 0; x < n; x++)
      if (!vis[x]) dfs1(x);
    reverse(todo.begin(), todo.end());
    for (int x : todo)
      if (comp[x] == -1) dfs2(x, time++);
    return comp;
  }
};

void solve(int n) {
    char c; cin >> c;

    map<char, int> letterToIndex;
    map<int, char> backwards;
    vector<vector<int>> adjList;
    vector<string> input;

    for (int i = 0; i < n; i++) {
        string word; cin >> word;
        input.push_back(word);
        for (char c : word) {
            if (letterToIndex.find(c) == letterToIndex.end()) {
                backwards[letterToIndex.size()] = c;
                letterToIndex[c] = letterToIndex.size();
            }
        }
    }

    int numLetters = letterToIndex.size();
    adjList = vector<vector<int>>(numLetters);
    for (int i = 0; i < numLetters; i++) {
        for (int j = 0; j < numLetters; j++) {
            if (i == j) continue;
            adjList[i].push_back(j);
        }
    }

    for (string s : input) {
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                if (i == j) continue;
                char u = letterToIndex[s[i]];
                char v = letterToIndex[s[j]];
                
                int vLocInU;
                for (vLocInU = 0; vLocInU < adjList[u].size(); vLocInU++)
                    if (adjList[u][vLocInU] == v)
                        break;
                int uLocInV;
                for (uLocInV = 0; uLocInV < adjList[v].size(); uLocInV++)
                    if (adjList[v][uLocInV] == u)
                        break;
                
                if (vLocInU < adjList[u].size())
                    adjList[u].erase(adjList[u].begin() + vLocInU);
                if (uLocInV < adjList[v].size())
                    adjList[v].erase(adjList[v].begin() + uLocInV);
            }
        }
    }

    for (int i = 0; i < adjList.size(); i++) {
        cout << backwards[i] << " --> ";
        for (auto v : adjList[i]) {
            cout << backwards[v] << ' ';
        }
        cout << nl;
    }

    auto sccs = SCCKosaraju::scc(adjList);
    for (int i : sccs) cout << i << ' ';
    cout << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    while (n != 0) {
        solve(n);
        cin >> n;
    }    
    return 0;
}
