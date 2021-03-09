#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, t; cin >> n >> t;
    vi a(n);
    map<int, int> numCounts;
    bool unique = true;
    int bigNum = -1;
    rep(i, 0, n) {
        cin >> a[i];
        if (++numCounts[a[i]] > n/2)
            bigNum = a[i];
        if (numCounts[a[i]] > 1)
            unique = false;
    }

    bool found = false;
    switch(t) {
        // a + b == 7777
        case 1:
            rep(i, 0, n) {
                int num = a[i];
                int comp = 7777 - num;
                if (numCounts[comp]) {
                    cout << "YES";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "NO";
            break;
        case 2:
            cout << (unique?"Unique":"Contains duplicate");
            break;
        case 3:
            cout << bigNum;
            break;
        case 4:
            sort(all(a));
            if (a.size()&1)
                cout << a[n/2];
            else
                cout << a[n/2-1] << ' ' << a[n/2];
            break;
        case 5:
            sort(all(a));
            rep(i, 0, n)
                if (a[i] >= 100 && a[i] <= 999)
                    cout << a[i] << ' ';
            break;
    }
    cout << '\n';

    return 0;    
}
