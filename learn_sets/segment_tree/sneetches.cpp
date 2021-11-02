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
	vi val = {0, 0};
	int lazy = 0;
	int leftType = -1, rightType = -1;
	int leftRun = 0, rightRun = 0;
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
			int type = config[lo] == 'S';
			meta.val = {type, !type};
			meta.leftType = type; meta.rightType = type;
			meta.leftRun = 1; meta.rightRun = 1;
		}
	}

	void prop() {
		if (meta.lazy) {
			left->meta.lazy ^= 1;
			right->meta.lazy ^= 1;
			meta.lazy = 0;
		}
	}

	info merge(info &leftNode, info &rightNode) {
		int actualLL = leftNode.leftType ^ leftNode.lazy;
		int actualLR = leftNode.rightType ^ leftNode.lazy;
		int actualRL = rightNode.leftType ^ rightNode.lazy;
		int actualRR = rightNode.rightType ^ rightNode.lazy;

		info ret;
		ret.leftType = actualLL;
		ret.rightType = actualRR;

		ret.leftRun = leftNode.leftRun;
		if (actualLL == actualLR && actualLR == actualRL)
			ret.leftRun += rightNode.leftRun;

		ret.rightRun = rightNode.rightRun;
		if (actualRR == actualRL && actualRL == actualLR)
			ret.rightRun += leftNode.rightRun;

		vi newVal = ret.val;
		newVal[0] = max(leftNode.val[leftNode.lazy], rightNode.val[rightNode.lazy]);
		newVal[1] = max(leftNode.val[!leftNode.lazy], rightNode.val[!rightNode.lazy]);

		newVal[actualLL] = max(newVal[actualLL], leftNode.leftRun);
		newVal[actualRR] = max(newVal[actualRR], rightNode.rightRun);
		if (actualLR == actualRL)
			newVal[actualLR] = max(newVal[actualLR], leftNode.rightRun + rightNode.leftRun);
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

