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

	srand(time(NULL));
	vi s;
	for (int i = 0; i < 10; i++)
		s.push_back(rand() % 10);
	vi suff = suffArray(s);

	for (int i : s)
		cout << i << ' ';
	cout << endl;
	for (int i : suff)
		cout << i << ' ';
	cout << endl;

	return 0;

	int n; cin >> n;
	map<int, int> comp;
	vector<vi> seq;
	for (int i = 0; i < n; i++) {
		int l; cin >> l;
		seq.push_back(vi(l));
		for (int j = 0; j < l; j++) {
			int val; cin >> val;
			if (comp[val] == 0)
				comp[val] = sz(comp);
			seq[i][j] = comp[val];
		}
	}

	vi suffVec;
	for (int i = 0; i < n; i++) {
		for (int val : seq[i])
			suffVec.push_back(val);
		suffVec.push_back(sz(comp) + 1);
	}
	suffVec.erase(suffVec.end() - 1);


    return 0;
}

