#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<int, vi> red, green, blue;
map<int, bool> stillExists;
map<int, vector<int>> dependencies;

struct card {
	int r, g, b, id, u;
	card(int r, int g, int b, int id) :
		r(r), g(g), b(b), id(id) {}
	card() {}
	int calcUniqueness() {
		int start = r;

		int redClosestUp, redClosestUpAngle;
		for (int iter = start, cnt = 0; iter <= start + 360; iter++, cnt++) {
			int angle = iter % 360;

			bool found = false;
			for (int id : red[angle])
				if (stillExists[id]) {
					redClosestUp = id;
					redClosestUpAngle = cnt;
					found = true;
					break;
				}
			if (found) break;
		}

		int redClosestDown, redClosestDownAngle;
		for (int iter = start, cnt = 0; iter >= start - 360; iter--, cnt++) {
			int angle = iter < 0 ? iter + 360 : iter;

			bool found = false;
			for (int id : red[angle])
				if (stillExists[id]) {
					redClosestDown = id;
					redClosestDownAngle = cnt;
					found = true;
					break;
				}
			if (found) break;
		}

		int greenClosestUp, greenClosestUpAngle;
		for (int iter = start, cnt = 0; iter <= start + 360; iter++, cnt++) {
			int angle = iter % 360;

			bool found = false;
			for (int id : green[angle])
				if (stillExists[id]) {
					greenClosestUp = id;
					greenClosestUpAngle = cnt;
					found = true;
					break;
				}
			if (found) break;
		}

		int greenClosestDown, greenClosestDownAngle;
		for (int iter = start, cnt = 0; iter >= start - 360; iter--, cnt++) {
			int angle = iter < 0 ? iter + 360 : iter;

			bool found = false;
			for (int id : green[angle])
				if (stillExists[id]) {
					greenClosestDown = id;
					greenClosestDownAngle = cnt;
					found = true;
					break;
				}
			if (found) break;
		}

		int blueClosestUp, blueClosestUpAngle;
		for (int iter = start, cnt = 0; iter <= start + 360; iter++, cnt++) {
			int angle = iter % 360;

			bool found = false;
			for (int id : blue[angle])
				if (stillExists[id]) {
					blueClosestUp = id;
					blueClosestUpAngle = cnt;
					found = true;
					break;
				}
			if (found) break;
		}

		int blueClosestDown, blueClosestDownAngle;
		for (int iter = start, cnt = 0; iter >= start - 360; iter--, cnt++) {
			int angle = iter < 0 ? iter + 360 : iter;

			bool found = false;
			for (int id : blue[angle])
				if (stillExists[id]) {
					blueClosestDown = id;
					blueClosestDownAngle = cnt;
					found = true;
					break;
				}
			if (found) break;
		}

		dependencies[id].clear();
		dependencies[id].push_back(redClosestDown);
		dependencies[id].push_back(redClosestUp);
		dependencies[id].push_back(greenClosestDown);
		dependencies[id].push_back(greenClosestUp);
		dependencies[id].push_back(blueClosestDown);
		dependencies[id].push_back(blueClosestUp);

		int redAngle = min(360 - abs(redClosestDownAngle - redClosestUpAngle), abs(redClosestDownAngle - redClosestUpAngle));
		int greenAngle = min(360 - abs(greenClosestDownAngle - greenClosestUpAngle), abs(greenClosestDownAngle - greenClosestUpAngle));
		int blueAngle= min(360 - abs(blueClosestDownAngle - blueClosestUpAngle), abs(blueClosestDownAngle - blueClosestUpAngle));

		int sum = redAngle + greenAngle + blueAngle;
		cout << sum << endl;
		return u = sum;
	}
};

map<int, card> cards;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; cin >> n;
	fill(all(stillExists), false);


Run command nvim +PlugInstall +UpdateRemotePlugins +qa in shell to install this plugin. Install corresponding language servers. Restart neovim/vim and language services will be available right away. Happy hacking!
Mappings

LanguageClient-neovim defines various Plug mappings, see :help LanguageClientMappings for a full list and an example configuration.
	vector<int> ids(n);
	for (int i = 0; i < n; i++) {
		int r, g, b, id; cin >> r >> g >> b >> id;
		ids[i] = id;
		red[r].push_back(id);
		green[g].push_back(id);
		blue[b].push_back(id);
		cards[id] = card(r, g, b, id);
	}

	set<pii> sortedIds;
	for (int i = 0; i < n; i++)
		sortedIds.emplace(cards[ids[i]].calcUniqueness(), ids[i]);

	// keep removing
	for (int i = 0; i < n - 1; i++) {
		int lowest = (begin(sortedIds))->second;
		cout << lowest << endl;
		stillExists[lowest] = false;
		sortedIds.erase(begin(sortedIds));

		for (int id : dependencies[lowest]) {
			auto it = sortedIds.find({cards[id].u, id});
			assert(it != sortedIds.end());
			sortedIds.erase(it);

			sortedIds.emplace(cards[id].calcUniqueness(), id);
		}
	}

	return 0;
}
