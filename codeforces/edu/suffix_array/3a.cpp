#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct SuffixArray {
	vi sa, lcp;
	SuffixArray(string& s, int lim=256) { // or basic_string<int>
		int n = sz(s) + 1, k = 0, a, b;
		vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		rep(i,1,n) rank[sa[i]] = i;
		for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	string s; cin >> s;
	SuffixArray suff(s);
	vi sa = suff.sa;
	sa.erase(begin(sa));

	int n; cin >> n;
	rep(i,0,n) {
		string p; cin >> p;

		bool found = false;
		int lo = 0, hi = sz(s) - 1;
		while (lo <= hi) {
			int m = (lo + hi) >> 1;
			int suffI = sa[m];
			string a = "";
			for (int c = suffI, cnt = 0; c < sz(s) && cnt < sz(p); c++, cnt++)
				a += s[c];
			if (a < p) lo = m + 1;
			else if (a > p) hi = m - 1;
			else {
				cout << "Yes";
				found = true;
				break;
			}
		}
		if (!found) cout << "No";
		cout << endl;
	}

    return 0;
}

