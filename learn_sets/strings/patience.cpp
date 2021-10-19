#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef vector<int> vi;

vi sortShifts(vi const& s) {
    int n = sz(s);
	vi p(n), c(n), cnt(n, 0);
	for (int i = 0; i < n; i++)
		cnt[s[i]]++;
	for (int i = 1; i < n; i++)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; i++)
		p[--cnt[s[i]]] = i;
	c[p[0]] = 0;
	int classes = 1;
	for (int i = 1; i < n; i++) {
		if (s[p[i]] != s[p[i - 1]])
			classes++;
		c[p[i]] = classes - 1;
	}

	vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vi suffArray(vi v) {
	v.push_back(0);
	vi sorted = sortShifts(v);
	sorted.erase(begin(sorted));
	return sorted;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

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

	map<int, int> comp;
	sort(all(vals));
	for (int i = 0; i < sz(vals); i++)
		comp[vals[i]] = i;

	vector<vi> og = seq;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < sz(seq[i]); j++)
			seq[i][j] = comp[seq[i][j]];

	vi conc;
	for (int i = 0; i < n; i++) {
		for (int val : seq[i])
			conc.push_back(val);
		conc.push_back(sz(comp) + 1);
	}
	conc.erase(conc.end() - 1);

	vi suff = suffArray(conc);
	vi inv(sz(suff));
	for (int i = 0; i < sz(suff); i++)
		inv[suff[i]] = i;

	// construct an array of seq[i][j] to suff ordering
	vector<vi> seqSuff = seq;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < sz(seq[i]); j++, idx++)
			seqSuff[i][j] = inv[idx];
		idx++;
	}

	vi ind(n, 0);
	vi res;
	while (true) {
		int bestIdx = -1;
		for (int i = 0; i < n; i++) {
			if (ind[i] == sz(seqSuff[i])) continue;
			if (bestIdx == -1 || seqSuff[bestIdx][ind[bestIdx]] > seqSuff[i][ind[i]])
				bestIdx = i;
		}
		if (bestIdx == -1) break;
		res.push_back(og[bestIdx][ind[bestIdx]]);
		ind[bestIdx]++;
	}

	for (int i : res) cout << i << ' ';
	cout << endl;

    return 0;
}

