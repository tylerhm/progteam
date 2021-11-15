#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vector<string> s1(n), s2(n);

    for (auto &x : s1) cin >> x;
    for (auto &x : s2) cin >> x;

    set<string> s;

    int curSize = 1;
    for (int i = 0; i < n; i++) {
        auto s1l = s.find(s1[i]);
        if (s1l == s.end())
            s.insert(s1[i]);
        else
            s.erase(s1l);
        auto s2l = s.find(s2[i]);
        if (s2l == s.end())
            s.insert(s2[i]);
        else
            s.erase(s2l);
        if (s.size() == 0) {
            cout << curSize << nl;
            curSize = 0;
        }
        curSize++;
    }

    if (curSize != 1)
        cout << curSize - 1 << nl;

    return 0;
}
