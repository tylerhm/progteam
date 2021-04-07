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

    vector<pair<char, int>> betterRep;
    string in; cin >> in;

    int curIndex = 0;
    betterRep.emplace_back(in[0], 1);
    for (int i = 1; i < in.length(); i++) {
        if (in[i] == betterRep[curIndex].first)
            betterRep[curIndex].second++;
        else {
            betterRep.emplace_back(in[i], 1);
            curIndex++;
        }
    }

    if (!(betterRep.size()&1)) {
        cout << 0 << "\n";
        return 0;
    }

    int lo = 0, hi = betterRep.size() - 1;
    while (lo < hi) {
        if (betterRep[lo].first != betterRep[hi].first) {
            cout << 0 << "\n";
            return 0;
        }
        if (betterRep[lo].second + betterRep[hi].second < 3) {
            cout << 0 << "\n";
            return 0;
        }
        lo++; hi--;
    }

    if (betterRep[lo].second >= 2)
        cout << betterRep[lo].second + 1 << "\n";
    else
        cout << 0 << "\n";

    return 0;    
}
