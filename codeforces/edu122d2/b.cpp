#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <map>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	string inp; cin >> inp;
	map<int, int> freq;

	for (char c : inp) freq[c - '0']++;

	// special case?
	if (freq[0] == freq[1]) {
		int best = 0;
		int zeros = 0, ones = 0;
		for (int i = 0; i < sz(inp); i++) {
			if (inp[i] == '0') zeros++;
			else ones++;
			if (!zeros || !ones) continue;
			if (zeros == ones) continue;
			best = max(best, min(zeros, ones));
		}

		zeros = 0, ones = 0;
		for (int i = sz(inp)-1; i >= 0; i--) {
			if (inp[i] == '0') zeros++;
			else ones++;
			if (!zeros || !ones) continue;
			if (zeros == ones) continue;
			best = max(best, min(zeros, ones));
		}

		cout << best << endl;
		return;
	}

	if (freq[0] == 0 || freq[1] == 0) {
		cout << 0 << endl;
		return;
	}

	cout << min(freq[0], freq[1]) << endl;
	return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();

    return 0;
}

