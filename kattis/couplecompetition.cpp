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
#include <queue>
#include <stack>

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

	int N; cin >> N;
	vector<ll> heights(N);
	ll mx = LLONG_MIN;
	for (int i = 0; i < N; i++) {
		ll x; cin >> x;
		mx = max(mx, x);
		heights[i] = x;
	}

	vector<vi> adj(N);
	stack<int> st;
	for (int i = N - 1; i >= 0; i--) {
		while (!st.empty() && heights[st.top()] < heights[i]) {
			adj[i].push_back(st.top());
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) st.pop();
	for (int i = 0; i < N; i++) {
		while (!st.empty() && heights[st.top()] < heights[i]) {
			adj[i].push_back(st.top());
			st.pop();
		}
		st.push(i);
	}

	queue<int> bfs;
	vector<ll> dist(N, -1);
	for (int i = 0; i < N; i++) {
		if (heights[i] == mx) {
			bfs.push(i);
			dist[i] = 0;
		}
	}

	while (!bfs.empty()) {
		int cur = bfs.front();
		bfs.pop();

		for (int i : adj[cur]) {
			if (i != -1 && dist[i] == -1) {
				dist[i] = dist[cur] + 1;
				bfs.push(i);
			}
		}
	}

	for (int i = 0; i < N; i++)
		cout << dist[i] << " ";
	cout << "\n";

    return 0;
}

