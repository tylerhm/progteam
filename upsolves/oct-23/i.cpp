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

	int n; cin >> n;
	if (n == 2 || n == 3 || n == 5) {
		cout << "impossible" << endl;
		return 0;
	}

	if (n == 1) {
		cout << "1 1 1" << endl;
		cout << "A 0 0 U" << endl;
		return 0;
	}

	if (!(n & 1)) {
		int aSize = 1;
		int cSize = n / 2;
		int bSize = cSize - 1;

		cout << aSize << ' ' << bSize << ' ' << cSize << endl;
		cout << "B 0 1 U" << endl;

		for (int i = 0; i < n - 1; i++)
			cout << "A " << (i/2) << ' ' << (i&1) << ' ' << (i&1 ? 'D' : 'U') << endl;
	} else {
		int aSize = 2;
		int bSize = (n - 5) / 2;
		int cSize = 2 * bSize + 2;
		cout << aSize << ' ' << bSize << ' ' << cSize << endl;

		cout << "B 2 0 U" << endl;
		cout << "B " << bSize + 2 << " 0 U" << endl;
		cout << "B 2 " << bSize << " U" << endl;
		cout << "B 2 " << bSize << " D" << endl;

		for (int i = 0; i < (n - 3) / 2; i++) {
			cout << "A 0 " << (2*i) << " U" << endl;
			if (i > 0) cout << "A 0 " << (2*i) << " D" << endl;
		}
	}

    return 0;
}

