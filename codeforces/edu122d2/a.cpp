#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
	string num; cin >> num;
	int num_i = stoi(num);
	if (num_i % 7 == 0) {
		cout << num_i << endl;
		return;
	}

	string newNum;
	for (int i = 0; i < sz(num); i++) {
		newNum = num;
		for (int j = (i == 0) ? 1 : 0; j <= 9; j++) {
			newNum[i] = '0' + j;
			int num_i = stoi(newNum);
			if (num_i % 7 == 0) {
				cout << num_i << endl;
				return;
			}
		}
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve(tc);

    return 0;
}

