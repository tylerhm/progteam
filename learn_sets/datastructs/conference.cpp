#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct room {
    string name;
    int t, id;

    room(int id, string name) : name(name), id(id), t(0) {}

    bool operator<(room const& o) const {
        return (t == o.t) ? (id < o.id) : (t < o.t);
    }
}

int calc(vector<pair<string, int>> &lecs, int time) {
    vector<room> ans;
    int tt = 0;

    priority_queue<room> pq;

    int i;
    rep(i, 0, time) {
        
        ans.emplace_back(i, lecs[i].first);

    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, t; cin >> n >> t;
    vector<pair<string, int>> lecs;

    string name; int time;
    rep(i, 0, n) {
        cin >> name >> time;
        lecs.emplace_back(name, time);
    }

    int lo = 1, hi = n, mid, rooms;

    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;

        int time = calc(lecs, mid);
        if (time <=)
    }

    return 0;    
}
