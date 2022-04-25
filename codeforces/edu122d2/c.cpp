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

void solve() {
	ll hc, dc; cin >> hc >> dc;
	ll hm, dm; cin >> hm >> dm;
	ll k, w, a; cin >> k >> w >> a;

	// all health
	ll nhc = hc + k * a;

	ll player_survive = nhc / dm + (nhc % dm != 0);
	ll monster_survive = hm / dc + (hm % dc != 0);

	if (player_survive >= monster_survive) {
		cout << "YES" << endl;
		return;
	}

	// all attack
	ll ndc = dc + k * w;

	player_survive = hc / dm + (hc % dm != 0);
	monster_survive = hm / ndc + (hm % ndc != 0);

	if (player_survive >= monster_survive) {
		cout << "YES" << endl;
		return;
	}


	// increase one life health, rest attack
	ll critical_health = hc % dm;
	if (critical_health == 0) critical_health = dm;

	ll coin_needed = critical_health / a + (critical_health % a != 0);
	ll can_take = min(coin_needed, k);
	nhc = hc + can_take * a;
	ll left = k - can_take;
	ndc = dc + left * w;

	player_survive = nhc / dm + (nhc % dm != 0);
	monster_survive = hm / ndc + (hm % ndc != 0);

	if (player_survive >= monster_survive) {
		cout << "YES" << endl;
		return;
	}

	// Kill monster one round earlier rest health
	critical_health = hm % dc;
	if (critical_health == 0) critical_health = dc;
	ll attacks_for_crit_health = hm / dc;
	ll bonus = attacks_for_crit_health * w;
	coin_needed = critical_health / bonus + (critical_health % bonus != 0);
	can_take = min(coin_needed, k);
	ndc = dc + can_take * w;
	left = k - can_take;
	nhc = hc + left * a;

	player_survive = nhc / dm + (nhc % dm != 0);
	monster_survive = hm / ndc + (hm % ndc != 0);

	if (player_survive >= monster_survive) {
		cout << "YES" << endl;
		return;
	}

	cout << "NO" << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();

    return 0;
}

