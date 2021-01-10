#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

struct pulse {
    int t, m, a;
    pulse(int t, int m, int a) : t(t), m(m), a(a) {}
    bool collides(pulse other) {
        int localStart = t - a;
        int localEnd = localStart + m;

        int otherStart = other.t - other.a;
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
    unordered_set<int> vertRange, horiRange;
    int count = 0;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        int t, m, a; cin >> t >> m >> a;
        if (c == 'v')
        {
            for (int i = (t - a); i < (t - a) + m; i++) vertRange.insert(i);

            for (int i = (t - a); i < (t - a) + m; i++) {
                if (horiRange.find(i) != horiRange.end()) {
                    count++;
                    break;
                }
            }
        }
        else 
        {
            for (int i = (t - a); i < (t - a) + m; i++) horiRange.insert(i);

            for (int i = (t - a); i < (t - a) + m; i++) {
                if (vertRange.find(i) != vertRange.end()) {
                    count++;
                    break;
                }
            }
        }
    }
    
    cout << count << endl;

    return 0;
}
