#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

vector<int> funs, dis;
map<pair<int, int>, int> memo;
int n, k, l;

int maxFun(int section, int fun, int dizziness) {
    if (section == n) return fun;

    pair<int, int> lookup = {section, dizziness};
    if (memo.count(lookup))
        return memo[lookup];

    int decayedDizzyness = dizziness-k;
    if (decayedDizzyness < 0) decayedDizzyness = 0;
    if (dizziness + dis[section] > l)
        return memo[lookup] = maxFun(section+1, fun, decayedDizzyness);
    else
        return memo[lookup] = max(maxFun(section+1, fun, decayedDizzyness), 
        maxFun(section+1, fun+funs[section], dizziness+dis[section]));
}

void solve() {
    funs = vector<int>(n);
    dis = vector<int>(n);
    for (int i = 0; i < n; i++) {
        int f, d; cin >> f >> d;
        funs[i] = f;
        dis[i] = d;
    }
    memo.clear();
    cout << maxFun(0, 0, 0) << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> n >> k >> l;
    while (n != 0 && k != 0 && l != 0) {
        solve();
        cin >> n >> k >> l;
    }

    return 0;
}
