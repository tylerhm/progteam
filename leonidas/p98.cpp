#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string divs[] = {"Western", "Central", "Eastern"};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    
    map<string, vector<pair<pair<int, string>, string>>> teams;
    vector<pair<string, string>> aggregated;
    string name, div, uni;
    rep(i, 0, n) {
        cin >> name >> div >> uni;
        teams[div].push_back({{i, name}, uni});
        aggregated.push_back({name, uni});
    }

    vector<pair<int, string>> winners;
    map<string, int> uniCount;
    vector<bool> taken(aggregated.size(), false);

    // step one
    int selected;
    for (string div : divs) {
        selected = 0;
        for (int i = 0; i < teams[div].size(), selected < 2; i++) {
            auto team = teams[div][i];
            if (!uniCount[team.second]) {
                winners.push_back(team.first);
                uniCount[team.second]++;
                selected++;
                taken[team.first.first] = true;
            }
        }
    }

    // step two
    selected = 0;
    for (int i = 0; i < aggregated.size(), selected < 6; i++) {
        auto team = aggregated[i];
        if (!taken[i] && uniCount[team.second] < 2) {
            winners.push_back({i, team.first});
            uniCount[team.second]++;
            selected++;
        }
    }
    
    sort(all(winners));
    for (auto winner : winners) cout << winner.second << endl;

    return 0;    
}
