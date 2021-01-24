#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

/*
6
Stephen Cook
Vinton Cerf
Edmund Clarke
Judea Pearl
Shafi Goldwasser
Silvio Micali
9
Richard Hamming
Marvin Minskey
John McCarthy
Edsger Dijkstra
Donald Knuth
Michael Rabin
John Backus
Robert Floyd
Tony Hoare
0

*/

bool on(int mask, int pos) { return (mask & (1 << pos)) > 0; }

void solve(int n) {
    // find all first names that can map to last name
    map<char, set<char>> lastToFirsts;
    set<char> possibleLasts;
    for (int i = 0; i < n; i++) {
        string first, last; cin >> first >> last;
        lastToFirsts[last[0]].insert(first[0]);
        possibleLasts.insert(last[0]);
    }

    // bitmask bruteforce on all possible usages of lastNames
    int lastSize = possibleLasts.size();
    vector<char> lasts(lastSize);
    copy(all(possibleLasts), lasts.begin());
    int ans = oo;
    for (int mask = 0; mask < (1 << lastSize); mask++) {
        set<char> visited;
        int cc = 0;
        for (int i = 0; i < lastSize; i++) {
            if (on(mask, i)) cc++;
            else
                for (auto first : lastToFirsts[lasts[i]])
                    visited.insert(first);
        }
        cc += visited.size();
        ans = min(ans, cc);
    }
    cout << ans << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    while (n != 0) {
        solve(n);
        cin >> n;
    }

    return 0;
}
