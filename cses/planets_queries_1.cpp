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

	int n, q; cin >> n >> q;
	const int lg = 31;
	int jmp[n][lg + 1];

	for (int i = 0; i < n; i++)
		cin >> jmp[i][0], jmp[i][0]--;

	for (int l = 1; l <= lg; l++)
		for (int i = 0; i < n; i++)
			jmp[i][l] = jmp[jmp[i][l-1]][l-1];

	for (int i = 0; i < q; i++) {
		int x, k; cin >> x >> k;
		x--;
		int highestBit = 31 - __builtin_clz(k);
		for (int l = 0; l <= highestBit; l++)
			if (k & (1 << l))
				x = jmp[x][l];
		cout << x+1 << nl;
	}

	return 0;
}

