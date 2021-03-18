#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string keys;
int matrix[10][10];
ll minTime = LLONG_MAX;

ll eval(vector<int> &perm) {

    vector<vector<int>> dist(10, vector<int>(10, 0));
    for (int i = 0; i < perm.size(); i++)
        for (int j = 0; j < perm.size(); j++)
            dist[perm[i]][perm[j]] = abs(i-j)+1;

    ll ans = dist[perm[0]][keys[0]-'0'];
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            ans += matrix[i][j]*dist[i][j];

    return ans;
}

void permute(int p, vector<bool> &used, vector<int>& perm) {
    if (p == perm.size()) {
        minTime = min(minTime, eval(perm));
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (!used[i]) {
            used[i] = true;
            perm[p] = i;
            permute(p + 1, used, perm);
            used[i] = false;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> keys;

    // Process transitions
    rep(i, 0, keys.size()-1) {
        int from = keys[i]-'0';
        int to = keys[i+1]-'0';
        matrix[from][to]++;
    }

    vector<bool> used(10, false);
    vector<int> perm(9);
    permute(0, used, perm);

    cout << minTime << "\n";
  
    return 0;    
}
