#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct school {
    string name;
    double score;
    school(string n, double s) : name(n), score(s) {}
    bool operator<(school a) {
        return score < a.score;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    map<string, pii> s;

    for (int i = 1; i <= n; i++) {
        string school; cin >> school;
        s[school].first += i;
        s[school].second++;
    }

    vector<school> sc;
    for (auto p : s) {
        sc.emplace_back(p.first, (double)p.second.first / (double)p.second.second);
    }

    sort(all(sc));

    for (auto p : sc) {
        cout << p.name << endl;
    }

    return 0;    
}
