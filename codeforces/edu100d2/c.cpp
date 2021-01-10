#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n; cin >> n;
    vector<pair<int, int>> comms(n);
    for (int i = 0; i < n; i++) {
        int t, x; cin >> t >> x;
        comms[i] = make_pair(t, x);
    }

    int successful = 0;
    ll currentX = 0;
    ll nextX = 0;
    for (int i = 0; i < n; i++) {
        // if we made it to our location, we can accept commands again
        if (currentX == nextX) nextX = comms[i].second;

        ll window;
        if (i + 1 < n) window = comms[i+1].first - comms[i].first;
        else window = oo;

        // try to move only far enough to be in window, and check it
        ll toMove = min(window, abs(nextX - currentX));
        // move in correct direction
        ll oldX = currentX;
        if (currentX < nextX) currentX += toMove;
        else currentX -= toMove;

        // check if the window is valid
        if (comms[i].second >= min(oldX, currentX) && comms[i].second <= max(oldX, currentX)) successful++;
    }
    cout << successful << nl;
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
