#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct station {
    vector<ll> votes;
    ll ogIndex;
    ll oppositionAdded;
    ll heuristic;

    station(vector<ll> res, ll i) {
        ogIndex = i;
        oppositionAdded = res[res.size() - 1];
        votes = res;
    }

    void calcHeuristic(ll favoredCandidate) {
        ll regularAdded = votes[favoredCandidate];
        heuristic = oppositionAdded - regularAdded;
    }

    bool operator<(station o) {
        return heuristic > o.heuristic;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m; cin >> n >> m;
    vector<station> polls;
    vector<ll> voteSums(n);
    ll oppositionScore = 0;
    rep(i, 0, m) {
        vector<ll> poll(n);
        for (auto &p: poll) cin >> p;
        polls.emplace_back(poll, i+1);

        oppositionScore += poll[poll.size() - 1];
        rep(i, 0, n) voteSums[i] += poll[i];
    }

    ll minRemovedSize = INT_MAX;
    vector<ll> minRemoved;

    // try all possible favored candidates
    rep(i, 0, n - 1) {
        for (auto &p : polls) p.calcHeuristic(i);
        sort(all(polls));

        int index = 0;
        vector<ll> removed;
        ll oppositionScoreCopy = oppositionScore;
        ll favoredScore = voteSums[i];
        while (oppositionScoreCopy > favoredScore) {
            station cur = polls[index++];
            oppositionScoreCopy -= cur.oppositionAdded;
            favoredScore -= cur.votes[i];
            removed.push_back(cur.ogIndex);
        }

        if (removed.size() < minRemovedSize) {
            minRemoved = removed;
            minRemovedSize = minRemoved.size();
        }
    }

    cout << minRemovedSize << "\n";
    if (minRemoved.size() > 0) {
        for (ll r : minRemoved) cout << r << " ";
        cout << "\n";
    }

    return 0;    
}
