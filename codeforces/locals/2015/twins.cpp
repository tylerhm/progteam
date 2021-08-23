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

    bool mack, zack;

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        
        mack = false;
        zack = false;
        for (int j = 0; j < 10; j++) {
            int num; cin >> num;
            cout << num << ' ';
            if (num == 18) mack = true;
            if (num == 17) zack = true;
        }

        cout << endl;

        if (mack && !zack) cout << "mack";
        if (zack && !mack) cout << "zack";
        if (zack && mack) cout << "both";
        if (!zack && !mack) cout << "none";
        cout << endl << endl;
    }

    return 0;    
}
