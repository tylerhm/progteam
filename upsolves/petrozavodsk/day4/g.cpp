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

const int mod = 1e9 + 7;
struct ModVal {
	ll val;
	ModVal() : val(0) {}
	ModVal(ll val) : val(val % mod) {}
	ModVal operator+(ModVal a) const { return (val + a.val) % mod; }
	ModVal operator-(ModVal a) const { return (((val - a.val) % mod) + mod) % mod; }
	ModVal operator*(ModVal a) const { return (val * a.val) % mod; }
	bool operator==(ModVal a) const { return val == a.val; }
	bool operator==(ll a) const { return *this == ModVal(a); }
	bool operator<(ModVal a) const { return val < a.val; }
	friend ostream& operator<<(ostream& os, const ModVal& a) {
		os << a.val;
		return os;
	}
};

void brute_best_perm(int n) {
	vector<ModVal> vals(n);
	srand(time(NULL));

try_again:
	for (auto &x : vals) x = ModVal(rand());
	map<ModVal, int> resFreq;
	for (int mask = 0; mask < (1 << n); mask++) {
		ModVal ans = 0;
		for (int b = 0; b < n; b++) {
			if ((1 << b) & mask) ans = ans * vals[b];
			else ans = ans + vals[b];
		}
		if (++resFreq[ans] >= 2)
			goto try_again;
	}

	for (auto x : vals) cout << x << ' ';
	cout << endl;
}

const int TEST_LEN = 16;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	// 189890852 334850122 418845307 874776110 689033408 352663625 955775882 547569214 28352296 568765465 791457458 511787088 933581781 193468278 124203008
	// brute_best_perm(TEST_LEN - 1);

	const ModVal perm[TEST_LEN] = {0, 189890852, 334850122, 418845307, 874776110, 689033408, 352663625, 955775882, 547569214, 28352296, 568765465, 791457458, 511787088, 933581781, 193468278, 124203008};

	int n; cin >> n;
	int suffEnd = n + 1; // exclusive
	int suffAddOnes = 0;
	vector<bool> isMult(n);

	while (true) {
		int beginning = max(0, suffEnd - TEST_LEN);
		int len = suffEnd - beginning;

		cout << "? ";
		for (int i = 0; i < beginning; i++) cout << "0 ";
		for (int i = beginning; i < suffEnd; i++) cout << perm[i - beginning] << " ";
		for (int i = suffEnd; i < n + 1; i++) cout << "1 ";
		cout << endl;

		int response; cin >> response;
		ModVal modRes(response);
		modRes = modRes - suffAddOnes;

		suffEnd = beginning + 1;
		for (int mask = 0; mask < (1 << (len - 1)); mask++) {
			ModVal ans = 0;
			for (int b = 0; b < (len - 1); b++) {
				if ((1 << b) & mask) ans = ans * perm[b + 1];
				else ans = ans + perm[b + 1];
			}
			if (ans == modRes) {
				for (int b = 0; b < len - 1; b++) {
					if ((1 << b) & mask)
						isMult[beginning + b] = true;
					else suffAddOnes++;
				}
				break;
			}
		}

		if (beginning == 0) break;
	}

	cout << "! ";
	for (bool m : isMult) cout << (m ? "x" : "+");
	cout << endl;

	return 0;
}

