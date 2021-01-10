#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

struct team {
    int k, da, db;
    bool operator<(team comp) {
        return abs(db-da) > abs(comp.db-comp.da);
    }
};

void solve(int t) {

}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, a, b; cin >> n >> a >> b;
    while (n != 0) {
        vector<team> teams(n);
        int k, da, db;
        ll dist = 0;
        for (int i = 0; i < n; i++) {
            cin >> k >> da >> db;
            teams[i].k = k;
            teams[i].da = da;
            teams[i].db = db;
        }
        sort(all(teams));

        for (int i = 0; i < n; i++) {
            int removed;
            k = teams[i].k;
            da = teams[i].da;
            db = teams[i].db;
            removed = k;
            if (da <= db && a > 0) {
                a -= removed;
                if (a < 0) {
                    removed += a;
                    a = 0;
                    dist += removed * da;
                }
                if (removed != k) {
                    b -= k - removed;
                    dist += (k - removed) * db;
                }
                else dist += k * da;
            }
            else {
                b -= removed;
                if (b < 0) {
                    removed += b;
                    b = 0;
                    dist += removed * db;
                }
                if (removed != k) {
                    a -= k - removed;
                    dist += (k - removed) * da;
                }
                else dist += k * db;
            }
        }

        cout << dist << "\n";
        cin >> n >> a >> b;
    }

    return 0;
}
