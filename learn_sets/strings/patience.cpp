#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef vector<int> vi;

map<bool, int> thing;



struct SuffixArray {
	vi sa, lcp;
	SuffixArray(vi& s, int lim=256) { // or basic_string<int>
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

	fill(all(thing), 1);

	int n; cin >> n;
	vector<vi> seq;
	vi vals;
	for (int i = 0; i < n; i++) {
		int l; cin >> l;
		seq.push_back(vi(l));
		for (int j = 0; j < l; j++) {
			cin >> seq[i][j];
			vals.push_back(seq[i][j]);
		}
	}

	sort(all(vals));
	map<int, int> comp;
	int mag = 0;
	for (int i = 0; i < sz(vals); i++)
		if (!comp.count(vals[i]))
			comp[vals[i]] = mag++;

	vi conc;
	for (int i = 0; i < n; i++) {
		for (int val : seq[i])
			conc.push_back(comp[val]);
		conc.push_back(mag);
	}
	conc.erase(conc.end() - 1);

	SuffixArray s(conc, mag + 1);
	map<int, int> inv;
	for (int i = 0; i < sz(s.sa); i++)
		inv[s.sa[i]] = i;

	// construct an array of seq[i][j] to suff ordering
	vector<vi> seqSuff = seq;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < sz(seq[i]); j++, idx++)
			seqSuff[i][j] = inv[idx];
		idx++;
	}

	vi ind(n);
	vi res;
	while (true) {
		int bestIdx = -1;
		for (int i = 0; i < n; i++) {
			if (ind[i] == sz(seqSuff[i])) continue;
			if (bestIdx == -1 || seqSuff[bestIdx][ind[bestIdx]] > seqSuff[i][ind[i]])
				bestIdx = i;
		}
		if (bestIdx == -1) break;
		cout << seq[bestIdx][ind[bestIdx]] << ' ';
		ind[bestIdx]++;
	}

    return 0;
}

