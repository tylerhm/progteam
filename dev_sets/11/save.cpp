#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

struct pulse {
    int t, m, a;
    pulse(int t, int m, int a) : t(t), m(m), a(a) {}
    bool collides(pulse other) {
        int lcs = a + t, lce = a + t + m;
        int ocs = other.a + other.t, oce = other.a + other.t + other.m;
        return (lcs >= ocs && lcs < oce || ocs >= lcs && ocs < lce);
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vector<pulse> hori, vert;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        int t, m, a; cin >> t >> m >> a;
        if (c == 'v') vert.emplace_back(t, m, a);
        else hori.emplace_back(t, m, a);
    }

    int count = 0;
    for (pulse h : hori)
        for (pulse v : vert)
            if (h.collides(v))
                count++;
    
    cout << count << endl;

    return 0;
}
