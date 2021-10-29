#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX_PLANETS = 2 * 1e5;
const int LG = 32;

int jmp[MAX_PLANETS][LG];
int pre[MAX_PLANETS], post[MAX_PLANETS];
bool visited[MAX_PLANETS];

int n, q, t;


void dfs(int v, int p) {

}

void lift() {
	t = 0;
	for (int i = 0; i < n; i++)
		if (!visited[i])
			dfs(i, i);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	cin >> n >> q;
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

