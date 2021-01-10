#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n; cin >> n;
    vector<int> song(n);
    set<int> seen;
    for (int i = 0; i < n; i++) {
        int note; cin >> note;
        if (seen.find(note) == seen.end()) seen.insert(note);
        else seen.insert(note+1);
    }

    cout << seen.size() << nl;
    
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
