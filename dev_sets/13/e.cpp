#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vector<int> cups(n);
    for (int i = 0; i < n; i++) cin >> cups[i];
    int k; cin >> k;

    queue<pair<vector<int>, int>> bfs;
    vector<int> curCups(n);
    curCups[0] = cups[0];
    for (int i = 1; i < n; i++) curCups[i] = 0;
    bfs.push(make_pair(curCups, 0));

    map<vector<int>, int> visited;
    visited[curCups] = 0;

    int minVol = oo;

    while (!bfs.empty()) {
        auto curState = bfs.front();
        vector<int> cupState = curState.first;
        int volume = curState.second;
        bfs.pop();

        bool foundChange = false;
        for (int i = 0; i < n; i++) {
            //cout << "Pouring from cup " << i << ":" << nl;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (cupState[i] == 0) continue;

                vector<int> modi = cupState;

                int curCup = modi[i];
                int nextCup = modi[j];
                int nextCupRemaining = cups[j] - nextCup;
                int moved;
                if (curCup >= nextCupRemaining) {
                    modi[i] -= nextCupRemaining;
                    modi[j] = cups[j];
                    moved = nextCupRemaining;
                }
                else {
                    modi[i] = 0;
                    modi[j] += curCup;
                    moved = curCup;
                }

                int newVol = volume + moved;
                if (newVol > minVol) continue;

                //cout << "\tPoured " << moved << " units into cup " << j << nl;

                if (modi[0] == k)
                    minVol = min(newVol, minVol);
                
                bool valid = true;
                if (visited.count(modi))
                    if (newVol >= visited[modi])
                        valid = false;
                if (!valid) continue;

                visited[modi] = newVol;

                bfs.push(make_pair(modi, volume + moved));
            }
        }
    }

    if (minVol == oo) cout << "impossible";
    else cout << minVol;
    cout << nl;

    return 0;
}
