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

void brute_grundy() {
	for (int b = 0; b < 10; b++) {
		cout << "Base: " << b+2 << endl;
		cout << 0 << ' ';
		vector<int> grundies(100, 0);
		for (int num = 1; num < 100; num++) {
			int exp = 1;
			set<int> seen;
			while (num - exp >= 0) {
				seen.insert(grundies[num - exp]);
				exp *= b + 2;
			}
			int grundy = 0;
			while (seen.count(grundy)) grundy++;
			grundies[num] = grundy;
			cout << grundy << ' ';
		}
		cout << endl << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	// Generate Grundies for first 20 bases to analyze
	// wow! 0.o they are all 0 1 2
	// brute_grundy();

	int N; cin >> N;
	int grundy = 0;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		if (b & 1) grundy ^= a % 2;
		else {
			ll modded = a % (b + 1);
			grundy ^= (modded == b) ? 2 : (modded & 1) ? 1 : 0;
		}
	}
	cout << (grundy == 0 ? "Bob" : "Alice") << "\n";

	return 0;
}

