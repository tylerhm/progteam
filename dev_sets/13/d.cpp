#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1 ^ 1 << 31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string first, second; cin >> first >> second;
    int fl = 0, sl = 0;
    map<char, int> pass;
    for (char c : first) pass[c]++;
    while (fl < first.size() && sl < second.size()) {
        if (pass[second[sl]]) {
            if (first[fl] != second[sl]) {
                cout << "FAIL" << nl;
                return 0;
            }
            fl++;
            pass[second[sl]]--;
        }
        sl++;
    }

    if (fl != first.size()) {
        cout << "FAIL" << nl;
        return 0;
    }

    cout << "PASS" << nl;

    return 0;
}
