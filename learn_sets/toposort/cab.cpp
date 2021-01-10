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

    char last; cin >> last;
    int n; cin >> n;
    int s = last-'a'+1;
    vector<set<int>> adjList(s);
    vector<int> ind(s);
    for (int i = 0; i < n; i++) {
        string inp; cin >> inp;
        for (int i = 0; i < inp.size()-1; i++) {
            if (inp[i] == inp[i+1]) continue;
            if (adjList[inp[i]-'a'].insert(inp[i+1]-'a').second)
                ind[inp[i+1]-'a']++;
        }
    }

    for (auto c : adjList) {
        for (int i : c) {
            cout << i << ' ';
        }
        cout << nl;
    }

    queue<int> topo;
    for (int i = 0; i < s; i++) {
        if (ind[i] == 0)
            topo.push(i);
    }

    int found = topo.size(), ways = found;
    vector<char> alph;
    while (!topo.empty()) {

        int s = topo.size(), additions = 0;
        for (int i = 0; i < s; i++) {
            int cur = topo.front();
            topo.pop();
            alph.push_back('a'+cur);

            for (int next : adjList[cur]) {
                if (--ind[next] == 0) {
                    topo.push(next);
                    found++;
                    additions++;
                }
            }
        }
        if (additions > 0) ways *= additions;
    }
    if (ways > 1 || found != s)
        cout << (found==s?1:0);
    else
        for (char c : alph) cout << c;
    cout << nl;

    return 0;
}
