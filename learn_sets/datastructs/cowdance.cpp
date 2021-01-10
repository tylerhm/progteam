#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

bool dance(vector<int> &cows, int k, int t) {
    priority_queue<int, vector<int>, greater<int>> stage;
    int time = 0;
    for (int i = 0; i < k; i++) {
        stage.push(cows[i]);
        time = max(time, cows[i]);
    }
    for (int i = k; i < cows.size(); i++) {
        int closest = stage.top();
        stage.pop();
        time = max(time, closest + cows[i]);
        stage.push(closest + cows[i]);
    }
    return time <= t;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, tmax; cin >> n >> tmax;
    vector<int> cows(n);
    for (int i = 0; i < n; i++) cin >> cows[i];
    
    // binary search on k
    int lo = 1;
    int hi = n;
    
    int k;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (dance(cows, mid, tmax)) {
            k = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }

    cout << k << nl;

    return 0;
}
