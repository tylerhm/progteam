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

    int n; cin >> n;
    vector<int> heights(n - 1);
    for (auto &x : heights) cin >> x;
    int t; cin >> t;
    int a, b;
    for (int tt = 1; tt <= t; tt++) {
        cin >> a >> b;
        int vol = 0, maxh = 0;
        a--; b--;
        if (a < b) {
            for (int i = b - 1; i >= a; i--) {
                maxh = max(maxh, heights[i]);
                vol += maxh; 
            }
            for (int i = a - 1; i >= 0; i--) {
                if (heights[i] < maxh) vol += maxh;
                else break;
            }
        }
        else {
            for (int i = b; i < a; i++) {
                maxh = max(maxh, heights[i]);
                vol += maxh; 
            }
            for (int i = a; i < n - 1; i++) {
                if (heights[i] < maxh) vol += maxh;
                else break;
            }
        }
        cout << vol << endl;
    }

    return 0;    
}