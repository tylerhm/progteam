#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

double pairDist(pair<int, int>& p1, pair<int, int>& p2) {
    return sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}

struct DSU {
    vector<int> s;
    DSU(int n) : s(n, -1) {}
    int find(int i) { return s[i] < 0 ? i : s[i] = find(s[i]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (s[a] > s[b]) swap(a, b);
        s[a] += s[b], s[b] = a;
        return true;
    }
    int size(int i) { return -s[find(i)]; }
    bool same(int a, int b) { return find(a) == find(b); }
};

int main()
{
    int n; cin >> n;
    int iter = 1;
    while (n != 0)
    {
        vector<pair<int, int>> locs = vector<pair<int, int>>(n);
        for (int i = 0; i < n; i++)
        {
            int x, y; cin >> x >> y;
            locs[i] = make_pair(x, y);
        }

        DSU dsu = DSU(n);
        // get closest neighbors
        vector<int> neighbors = vector<int>();
        for (int i = 0; i < n; i++) {
            double minDist = INT_MAX, dist;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                dist = pairDist(locs[i], locs[j]);
                if (dist < minDist) {
                    neighbors.clear();
                    neighbors.push_back(j);
                    minDist = dist;
                }
                else if (dist == minDist)
                    neighbors.push_back(j);
            }
            for (int nei : neighbors)
                dsu.join(i, nei);
        }

        unordered_set<int> constsellations = unordered_set<int>();
        for (int i = 0; i < n; i++) constsellations.insert(dsu.find(i));
        int consts = constsellations.size();
        cout << "Universe " << iter++ << " contains " << consts << " constellations\n";

        cin >> n;
    }
    return 0;
}
