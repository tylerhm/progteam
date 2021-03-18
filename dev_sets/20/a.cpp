#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    map<string, int> dwarfToIdx;
    map<int, string> idxToDwarf;

    vector<vector<int>> adjList;
    vector<int> inDegrees;

    rep(i, 0, n) {
        string first; cin >> first;
        char relate; cin >> relate;
        string second; cin >> second;

        if (!dwarfToIdx.count(first)) {
            idxToDwarf[dwarfToIdx.size()] = first;
            dwarfToIdx[first] = dwarfToIdx.size();
            adjList.push_back(vector<int>());
            inDegrees.push_back(0);
        }
        if (!dwarfToIdx.count(second)) {
            idxToDwarf[dwarfToIdx.size()] = second;
            dwarfToIdx[second] = dwarfToIdx.size();
            adjList.push_back(vector<int>());
            inDegrees.push_back(0);
        }

        int from, to;
        if (relate == '<') {
            from = dwarfToIdx[first];
            to = dwarfToIdx[second];
        }
        else {
            from = dwarfToIdx[second];
            to = dwarfToIdx[first];
        }

        adjList[from].push_back(to);
        inDegrees[to]++;
    }

    queue<int> topo;
    rep(i, 0, adjList.size())
        if (inDegrees[i] == 0)
            topo.push(i);

    int found = 0;

    while (!topo.empty()) {
        int s = topo.size();
        for (int i = 0; i < s; i++) {
            int cur = topo.front();
            topo.pop();

            for (int next : adjList[cur])
                if (--inDegrees[next] == 0)
                    topo.push(next);
                    found++;
        }
    }

    cout << (found==adjList.size()?"possible":"impossible") << "\n";

    return 0;    
}
