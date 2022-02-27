#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
    int n, t; cin >> n >> t;
    vi times(n);
    for (auto &x : times) cin >> x;
    sort(all(times));
    int taken = 0;
    int totalTime = 0;
    int timeSum = 0;
    for (int i = 0; i < n; i++) {
        if (timeSum + times[i] > t) break;
        taken++;
        timeSum += times[i];
        totalTime += timeSum;
    }

    cout << "Case " << tc << ": " << taken << ' ' << timeSum << ' ' << totalTime << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int i = 1; i <= t; i++)
      solve(i);

    return 0;
}

