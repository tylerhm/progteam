#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
	freopen("bad_test.out", "w", stdout);

	cout << (int)1e9 << ' ' << (int)1e5 << endl;
	for (int i = 0; i < (int)1e5 * 3 - 3; i += 3) {
		cout << i+1 << ' ' << i << endl;
	}

	cout << ((int)1e5*3/2) << ' ' << ((int)1e5*3/2 + 1) << endl;

    return 0;
}


