#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int t) {
    int n; cin >> n;

    // Split into two groups, size 2 and n-1
    vector<int> g1(2);
    vector<int> g2(n-1);

    // Add numbers 1-2 and 3-n+3
    int nextNumber = 1;
    for (int i = 0; i < 2; i++) g1[i] = nextNumber++;
    for (int i = 0; i < n-1; i++) g2[i] = nextNumber++;

    while (true) {

        if (nextNumber > 2*n + 1) break;

        int g1min = 0;
        for (int i = 1; i < g1.size(); i++) {
            cout << "? " << g1[i] << " " << g1[g1min] << endl;
            string result; cin >> result;
            if (result == "<") g1min = i;
        }

        int g2min = 0;
        for (int i = 1; i < g2.size(); i++) {
            cout << "? " << g2[i] << " " << g2[g2min] << endl;
            string result; cin >> result;
            if (result == "<") g2min = i;
        }

        cout << "? " << g1[g1min] << " " << g2[g2min] << endl;
        string result; cin >> result;

        if (result == "<")
            g1[g1min] = nextNumber++;
        else
            g2[g2min] = nextNumber++;
    }

    cout << "!" << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 0; tt < t; tt++) solve(t);

    return 0;    
}
