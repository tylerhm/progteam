#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int blocks[100'001];

bool backtrack(vector<int>& blocks, )

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    rep(i, 0, n) cin >> blocks[i];

    cout << (backtrack(blocks) ? "YES" : "NO") << endl;

    return 0;    
}
