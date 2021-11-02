#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct info {
	vi val = {1, 0};
	int lazy = 0;
	int leftType = 0, rightType = 0;
	int leftRun = 1, rightRun = 1;
};

struct seg {
	int lo, hi, mid;
	info meta;
	seg *left = nullptr, *right = nullptr;

	seg(int l, int r, string &config) {
		lo = l; hi = r; mid = (lo + hi) >> 1;
		if (lo != hi) {
			left = new seg(lo, mid, config);
			right = new seg(mid + 1, hi, config);
			meta = merge(left->meta, right->meta);
		} else {
			meta.lazy = config[lo] == 'S';
		}
	}

	void prop() {
		if (meta.lazy) {
			if (!left) {
				cout << "WA" << endl;
				exit(0);
			}
			left->meta.lazy ^= 1;
			right->meta.lazy ^= 1;
			meta.lazy = 0;
		}
	}

	info merge(info &leftMeta, info &rightMeta) {
		int actualLL = leftMeta.leftType ^ leftMeta.lazy;
		int actualLR = leftMeta.rightType ^ leftMeta.lazy;
		int actualRL = rightMeta.leftType ^ rightMeta.lazy;
		int actualRR = rightMeta.rightType ^ rightMeta.lazy;

		info ret;
		ret.leftType = actualLL;
		ret.rightType = actualRR;

		ret.leftRun = leftMeta.leftRun;
		if (actualLL == actualLR && actualLR == actualRL)
			ret.leftRun += rightMeta.leftRun;

		ret.rightRun = rightMeta.rightRun;
		if (actualRR == actualRL && actualRL == actualLR)
			ret.rightRun += leftMeta.rightRun;

		vi newVal(2);
		newVal[0] =
			max(leftMeta.val[leftMeta.lazy], rightMeta.val[rightMeta.lazy]);
		newVal[1] =
			max(leftMeta.val[!leftMeta.lazy], rightMeta.val[!rightMeta.lazy]);

		newVal[actualLL] = max(newVal[actualLL], leftMeta.leftRun);
		newVal[actualRR] = max(newVal[actualRR], rightMeta.rightRun);
		if (actualLR == actualRL)
			newVal[actualLR] =
				max(newVal[actualLR], leftMeta.rightRun + rightMeta.leftRun);
		ret.val = newVal;

		return ret;
	}

	void flip(int l, int r) {
		// no cover
		if (r < lo || l > hi) return;
		// full cover
		if (l <= lo && r >= hi) {
			meta.lazy ^= 1;
		} else {
			prop();
			left->flip(l, r);
			right->flip(l, r);
			meta = merge(left->meta, right->meta);
		}
	}
};

void solve(int t) {
	int n, s; cin >> n >> s;
	string config; cin >> config;
	seg tree(0, n-1, config);

	for (int i = 0; i < s; i++) {
		int l, r; cin >> l >> r;
		l--; r--;
		tree.flip(l, r);
		tree.prop();
		cout << tree.meta.val[1] << ' ' << tree.meta.val[0] << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++)
		solve(tt);

	return 0;
}

