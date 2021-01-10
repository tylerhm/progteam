#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

string solve(int t) {
    string inp; cin >> inp;
    int size = 0;
    for (int i = 0; i < inp.size(); i++) {
        char c = inp[i];
        if (c == '(') {
            if (i == inp.size() - 1) return "NO";
            size++;
        }
        else if (c == ')') {
            if (size == 0) return "NO";
            else size--;
        }
        else
            size++;
    }
    if (size&1)
        return "NO";
    return "YES";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tt; cin >> tt;
    for (int t = 1; t <= tt; t++)
        cout << solve(t) << nl;

    return 0;
}
