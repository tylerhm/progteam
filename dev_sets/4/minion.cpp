#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

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
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        int t; cin >> t;
        vector<string> badTrials = vector<string>(t);
        for (int i = 0; i < t; i++) cin >> badTrials[i];
        int n, e; cin >> n >> e;
        DSU dsu = DSU(n);
        for (int i = 0; i < e; i++)
        {
            int la, lb; cin >> la >> lb;
            string q; cin >> q;
            if (find(badTrials.begin(), badTrials.end(), q) == badTrials.end())
                dsu.join(la, lb);
        }
        cout << dsu.same(0, n-1) << "\n";
    }
    return 0;
}
