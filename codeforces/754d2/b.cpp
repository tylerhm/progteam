#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tt) {
	int len; cin >> len;
	string word; cin >> word;
	bool good = true;
	for (int i = 0; i < sz(word) - 1; i++) {
		if (word[i] > word[i+1]) {
			good = false;
			break;
		}
	}

	if (good) {
		cout << 0 << nl;
		return;
	}

	int lo = 0, hi = len - 1;
	vi seq;
	while (lo < hi) {
		if (word[lo] == '1' && word[hi] == '0') {
			seq.push_back(lo++);
			seq.push_back(hi--);
		} else {
			if (word[lo] == '1') hi--;
			else lo++;
		}
	}

	sort(all(seq));
	cout << 1 << nl << sz(seq) << ' ';
	for (int i : seq) cout << i+1 << ' ';
	cout << nl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++)
		solve(tt);

    return 0;
}

