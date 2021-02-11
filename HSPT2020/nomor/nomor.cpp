#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

void solve() {
	string line; getline(cin, line);
	for (char c : line)
		if (c != 'e')
			cout << c;
	cout << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int tt; cin >> tt;
	string newLinesSucc; getline(cin, newLinesSucc);
	for (int t = 0; t < tt; t++)
		solve();

    return 0;
}
