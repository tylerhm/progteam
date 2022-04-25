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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	string one, two;
	cin >> one >> two;
	map<char, bool> has;
	for (char c : one) has[c] = false;

	int wrong = 0;
	for (char c : two) {
		if (!has.count(c)) {
			if (++wrong == 10) {
				cout << "LOSE\n";
				return 0;
			}
		} else has[c] = true;

		bool done = true;
		for (char c : one) if (!has[c])
			done = false;

		if (done) {
			cout << "WIN\n";
			return 0;
		}
	}

	cout << "LOSE\n";

    return 0;
}

