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

set<ll> vals;

void eval(string s) {
	ll curVal = 0;
	ll running = 0;
	for (char c : s) {
		if (c == '+') {
			running += curVal;
			curVal = 0;
		} else {
			curVal *= 10;
			curVal += c - '0';
		}
	}
	curVal += running;
	vals.insert(curVal);
}

void go(string str, int idx) {
	if (idx >= sz(str)) {
		eval(str);
		return;
	}

	go(str, idx + 1);
	if (str[idx] == '+') {
		str.erase(idx, 1);
		go(str, idx);
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	string phrase; cin >> phrase;
	vals.clear();
	go(phrase, 0);

	cout << sz(vals) << endl;

    return 0;
}

