#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    set<string> se, s;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string inp; cin >> inp;
        if (inp[0] == '!')
            se.insert(inp.substr(1));
        else s.insert(inp);
        string noE = inp[0]=='!'?inp.substr(1):inp;
        if (se.count(noE) && s.count(noE)) {
            cout << noE << nl;
            return 0;
        }
    }

    cout << "satisfiable" << nl;

    return 0;
}
