#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n, k; cin >> n >> k;
    vector<int> ground(n);
    for (int i = 0; i < n; i++) cin >> ground[i];
    
    // generate possible range for all pieces
    // make sure that they all overlap
    vector<pair<int, int>> fences(n);
    if (ground[1] > ground[0])
        fences[0] = make_pair(ground[0] + k - 1, ground[0] + 2*k - 1);
    else
        fences[0] = make_pair(ground[0], ground[0] + k);
    if (ground[n-1] < ground[n-2])
        fences[n-1] = make_pair(ground[n-1] + k - 1, ground[n-1] + 2*k - 1);
    else
        fences[n-1] = make_pair(ground[n-1], ground[n-1] + k);

    for (int i = 1; i < n-1; i++) {
        if (ground[i] > ground[i-1]) {
            if (ground[i+1] > ground[i])
                fences[i] = make_pair(fences[i-1].second-1, fences[i-1].second-1+k);
            else
                fences[i] = make_pair(ground[i], ground[i]+k);
        }
        else {
            if (ground[i+1] < ground[i])
                fences[i] = make_pair(fences[i-1].first-k+1, fences[i-1].first+1);
            else
                fences[i] = make_pair(ground[i]+k-1, ground[i]+2*k-1);
        }
    }

    for (int i = 1; i < fences.size(); i++) {
        if (fences[i].first >= fences[i-1].second || fences[i].first < fences[i-1].first-k+1) {
            cout << "NO" << nl;
            return;
        }
        if (fences[i].first < ground[i] || fences[i].first >= ground[i] + k) {
            cout << "NO" << nl;
            return;
        }
    }

    cout << "YES" << nl;
    return;
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
