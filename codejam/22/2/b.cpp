#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <list>
#include <numeric>
#include <random>
#include <tuple>
#include <map>
#include <set>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int N; cin >> N;

	vi left, right;
	ll leftSum = 0, rightSum = 0;
	int lg = 0, pw = 1;
	vi pws(30);
	vector<bool> used(30, false);
	for (; lg < 30 && lg < N; lg++) {
		cout << pw << " ";
		pws[lg] = pw;
		pw *= 2;
	}

	int num = 3;
	for (int i = 0; i < (N - lg); i++) {
		while (__builtin_popcount(num) == 1) num++;
		cout << num << " ";
		if (leftSum <= rightSum) {
			leftSum += num;
			left.push_back(num);
		} else {
			rightSum += num;
			right.push_back(num);
		}
		num++;
	}
	cout << "\n";
	cout.flush();

	for (int i = 0; i < N; i++) {
		cin >> num;
		if (leftSum <= rightSum) {
			leftSum += num;
			left.push_back(num);
		} else {
			rightSum += num;
			right.push_back(num);
		}
	}

	int diff = abs(leftSum - rightSum);
	bool takeLeft = leftSum < rightSum;
	for (int pw = 29; pw >= 0; pw--) {
		if (pws[pw] <= diff) {
			diff -= pws[pw];
			used[pw] = true;
			if (takeLeft) left.push_back(pws[pw]);
			else right.push_back(pws[pw]);
		}
	}

	leftSum = rightSum = 0;
	for (int i : left) leftSum += i;
	for (int i : right) rightSum += i;
	cout << leftSum << " " << rightSum << "\n";
	for (int pw = 0; pw < 30; pw++) if (!used[pw]) {
		cout << pw << "\n";
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();

    return 0;
}

