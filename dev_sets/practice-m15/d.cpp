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
    vector<pair<int, int>> favs(n);
    for (int i = 0; i < n; i++) {
        cin >> favs[i].first;
        favs[i].second = i+1;
    }

    int curLoc = 0;
    while (favs.size() > 1) {
        int toMove = favs[curLoc].first;
        curLoc = (curLoc + toMove - 1) % favs.size();
        favs.erase(favs.begin() + curLoc);
        curLoc %= favs.size();
    }

    cout << favs[0].second << '\n';

    return 0;    
}
