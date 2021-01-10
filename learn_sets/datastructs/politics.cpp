#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

struct supp {
    string name;
    int prio;
    supp(string n, int p) : name(n), prio(p) {}
};

bool suppSort(supp const& a, supp const& b) {
        return a.prio < b.prio;
}

void solve(int t) {

}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m; cin >> n >> m;
    while (!(n == 0 && m == 0)) {
        map<string, int> candPrios;
        for (int i = 0; i < n; i++) {
            string cand; cin >> cand;
            if (candPrios.find(cand) == candPrios.end()) 
                candPrios[cand] = candPrios.size();
        }

        vector<supp> supps;
        for (int i = 0; i < m; i++) {
            string supp, cand; cin >> supp >> cand;
            if (candPrios.find(cand) == candPrios.end())
                candPrios[cand] = candPrios.size();
            supps.emplace_back(supp, candPrios[cand]);
        }

        stable_sort(all(supps), suppSort);

        for (supp s : supps)
            cout << s.name << nl;

        cin >> n >> m;
    }

    return 0;
}
