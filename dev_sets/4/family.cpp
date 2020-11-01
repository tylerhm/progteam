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
    int n; cin >> n;
    int iter = 1;
    while (n != 0)
    {
        unordered_map<string, int> names;
        DSU dsu = DSU(n*3 + 10);
        int personIndex = 0;
        for (int i = 0; i < n; i++) {
            vector<string> ppl = vector<string>();
            string p1, p2, c; cin >> p1 >> p2 >> c;
            ppl.push_back(p1);
            ppl.push_back(p2);
            ppl.push_back(c);
            for (string p : ppl) {
                auto person = names.find(p);
                if (person == names.end())
                    names[p] = personIndex++;
            }
            dsu.join(names.find(p1)->second, names.find(p2)->second);
            dsu.join(names.find(p2)->second, names.find(c)->second);
        }
        vector<string> ppl = vector<string>();
        string p1, p2; cin >> p1 >> p2;
        ppl.push_back(p1);
        ppl.push_back(p2);
        for (string p : ppl) {
            auto person = names.find(p);
            if (person == names.end())
                names[p] = personIndex++;
        }
        cout << "Family #" << iter << ": " << (dsu.same(names.find(p1)->second, names.find(p2)->second)? "Related.": "Not related.") << "\n";

        cin >> n;
        iter++;
    }
    return 0;
}
