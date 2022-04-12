#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int freq[(int)7e7];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int N; cin >> N;
	vi nums(N);
	for (auto &x : nums)
		cin >> x;

	int sqrtBound = ceil(sqrt(1e5));

	int off = 7e7 / 2;
	int ans = 0;
	//*
	for (int slope = -sqrtBound; slope < sqrtBound; slope++) {
		for (int i = 0; i < N; i++)
			ans = max(ans, ++freq[off + (nums[i] - slope * i)]);
		for (int i = 0; i < N; i++)
			freq[off + (nums[i] - slope * i)] = 0;
	}
	//*/

	//*
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < min(N, i + sqrtBound + 1); j++) {
			if (i == j) continue;
			ll num = nums[j] - nums[i];
			ll den = j - i;
			if (num % den != 0) continue;
			freq[off + (num / den)]++;
		}
		for (int j = i + 1; j < min(N, i + sqrtBound + 1); j++) {
			if (i == j) continue;
			ll num = nums[j] - nums[i];
			ll den = j - i;
			if (num % den != 0) continue;
			ll slope = off + (num / den);
			ans = max(ans, freq[slope] + 1);
			freq[slope] = 0;
		}
	}
	//*/

	cout << N - ans << "\n";
	return 0;
}

