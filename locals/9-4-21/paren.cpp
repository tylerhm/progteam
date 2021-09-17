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

    string gross;
    getline(cin, gross);

    vector<char> inp;
    for (char c : gross) {
        if (c != ' ') inp.push_back(c);
    }

    vector<int> depths(inp.size(), 0);

    int depth = 0;
    for (int i = 0; i < depths.size(); i++) {
        if (inp[i] == '(') depth++;
        depths[i] = depth;
        if (inp[i] == ')') depth--;
    }

    ll ans = 0;
    for (int i = 0; i < depths.size(); i++) {
        // find maximum depth between
        if (inp[i] == '(') {
            int curDepth = depths[i];
            int maxDepth = curDepth;
            for (int j = i + 1; j < depths.size() && depths[j] != curDepth; j++) {
                maxDepth = max(maxDepth, depths[j]);
            }
            // difference is the number of inside
            int inside = maxDepth - curDepth + 1;
            ans += inside;
        }
    }

    cout << ans << endl;

    return 0;    
}
