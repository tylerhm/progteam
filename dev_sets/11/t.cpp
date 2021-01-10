#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

struct pulse {
    int t, m, a;
    pulse(int t, int m, int a) : t(t), m(m), a(a) {}
    bool collides(pulse other) {
        int localStart = 0;
        int localEnd = m;

        int otherStart = (other.t - t) + (a - other.a);
        int otherEnd = otherStart + other.m;

        return (localStart >= otherStart && localStart < otherEnd ||
                otherStart >= localStart && otherStart < localEnd);
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vector<pulse> hori, vert;
    int count = 0;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        int t, m, a; cin >> t >> m >> a;
        if (c == 'v')
        {
            vert.emplace_back(t, m, a);
            for (int i = 0; i < hori.size(); i++)
                 if (vert[vert.size()-1].collides(hori[i]))
                    count++;
        }
        else 
        {
            hori.emplace_back(t, m, a);
            for (int i = 0; i < vert.size(); i++)
                 if (hori[hori.size()-1].collides(vert[i]))
                    count++;
        }
    }
    
    cout << count << endl;

    return 0;
}
