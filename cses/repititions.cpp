#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string inp; cin >> inp;
    int run = 0, maxRun = 0;
    char runChar = 'A';
    for (char c : inp) {
        if (c == runChar)
            run++;
        else {
            if (run > maxRun) maxRun = run;
            run = 1;
            runChar = c;
        }
    }
    if (run > maxRun) maxRun = run;
    cout << maxRun << "\n";

    return 0;
}
