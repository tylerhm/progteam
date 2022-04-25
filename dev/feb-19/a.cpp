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
#include <numeric>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct combo {
	ll front, back;
	ll ogFront, ogBack;
	combo(int _front, int _back) {
		ogFront = _front;
		ogBack = _back;
		int _gcd = gcd(_front, _back);
		_front /= _gcd;
		_back /= _gcd;
		front = _front;
		back = _back;
	}
	bool operator<(const combo &a) const {
		if (front == a.front && back == a.back) return ogFront < a.ogFront;
		return front * a.back < back * a.front;
	}
	friend ostream& operator<<(ostream &os, const combo &c) {
		return os << "(" << c.ogFront << "," << c.ogBack <<  ")";
	}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int f, b; cin >> f >> b;
	vector<int> front(f), back(b);
	for (auto &x : front) cin >> x;
	for (auto &x : back) cin >> x;

	vector<combo> combos;
	for (int i = 0; i < f; i++)
		for (int j = 0; j < b; j++)
			combos.emplace_back(front[i], back[j]);

	sort(all(combos));
	for (auto c : combos) cout << c << "\n";

    return 0;
}

