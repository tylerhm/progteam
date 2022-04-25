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

	int n, m; cin >> n >> m;
	vector<int> inDeg(n), outDeg(n);
	map<string, int> comp;

	for (int i = 0; i < n; i++) {
		string animal; cin >> animal;
		if (!comp.count(animal))
			comp[animal] = sz(comp);

		int num; cin >> num;
		outDeg[comp[animal]] = num;
		for (int j = 0; j < num; j++) {
			string next; cin >> next;
			if (!comp.count(next))
				comp[next] = sz(comp);
			inDeg[comp[next]]++;
		}
	}

	bool inDiffOne = false, outDiffOne = false;
	for (int i = 0; i < n; i++) {
		if (inDeg[i] == outDeg[i]) continue;
		if (abs(inDeg[i] - outDeg[i]) >= 2) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		if (inDeg[i] < outDeg[i]) {
			if (inDiffOne) {
				cout << "IMPOSSIBLE\n";
				return 0;
			}
			inDiffOne = true;
		}
		else {
			if (outDiffOne) {
				cout << "IMPOSSIBLE\n";
				return 0;
			}
			outDiffOne = true;
		}
	}

	cout << "POSSIBLE\n";

    return 0;
}

