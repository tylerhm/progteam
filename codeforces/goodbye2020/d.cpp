#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n; cin >> n;
    vector<pair<int, int>> inDegWeights(n);
    for (int i = 0; i < n; i++) {
        int w; cin >> w;
        inDegWeights[i].first = w;
    } 
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--;
        v--;
        inDegWeights[u].second++;
        inDegWeights[v].second++;
    }
    sort(all(inDegWeights));
    ll sum = 0;
    for (int i = 0; i < n; i++) sum += inDegWeights[i].first;
    cout << sum << " ";
    for (int i = n - 1; i >= 0; i--) {
        // solve for and print the ith k coloring
        // we want to 'duplicate' the largest elements as many times as possible
        // find largest element with indegree greater than 1
        // using this node now.
        for (int j = 0; j < inDegWeights[i].second - 1; j++) {
            sum += inDegWeights[i].first;
            cout << sum << " ";
        }
    }
    cout << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tt; cin >> tt;
    for (int t = 1; t <= tt; t++)
        solve(t);

    return 0;
}
