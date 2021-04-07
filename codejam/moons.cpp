#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll startingCost(string inp, int cjCost, int jcCost) {
    ll cost = 0;
    for (int i = 1; i < inp.length(); i++)
        if (inp[i] != '?' && inp[i-1] != '?' && inp[i - 1] != inp[i])
            cost += (inp[i-1] == 'C') ? cjCost : jcCost;
    return cost;
}

void solve(int t) {

    int cjCost, jcCost; cin >> cjCost >> jcCost;
    string inp; cin >> inp;

    ll totalCost = startingCost(inp, cjCost, jcCost);
    for (int i = 0; i < inp.length();) {
        if (inp[i] == '?') {
            int startIndex = i;
            int endIndex = startIndex;
            for (; endIndex < inp.length() && inp[endIndex] == '?'; endIndex++);
            endIndex--;

            int len = endIndex - startIndex + 1;

            // J??????C
            // either
            // continue Js --> cost = JC
            // or commit to Cs cost = CJ
            if (startIndex - 1 >= 0 && endIndex + 1 < inp.length())
                if (inp[startIndex - 1] != inp[endIndex + 1])
                    totalCost += (inp[startIndex-1] == 'C') ? cjCost : jcCost;
            i = endIndex + 1;
        }
        i++;
    }

    cout << "Case #" << t << ": " << totalCost << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
        solve(tt);

    return 0;    
}
