#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<int, int> upsideDown = {
  {0, 0},
  {1, 1},
  {2, 2},
  {3, -1},
  {4, -1},
  {5, 5},
  {6, 9},
  {7, -1},
  {8, 8},
  {9, 6},
};

int flip(int x) {
  int flipped = 0;
  int digit;
  while (x > 0) {
    digit = upsideDown[x % 10];
    if (digit == -1) return -1;
    flipped *= 10;
    flipped += digit;
    x /= 10;
  }
  return flipped;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, s; cin >> n >> s;
  vector<int> nums(n);
  for (auto &x : nums) cin >> x;

  map<int, set<int>> numsToLocs;

  for (int i = 0; i < n; i++) {
    numsToLocs[nums[i]].insert(i);
    int flipped = flip(nums[i]);
    if (flipped != -1 && flipped != nums[i])
      numsToLocs[flipped].insert(i);
    nums.push_back(flipped);
  }

  bool flippedVals = false;
  rep(i, 0, nums.size()) {
    if (i >= n) flippedVals = true;
    int a = nums[i];
    int b = s - a;
    if (numsToLocs.find(b) == numsToLocs.end()) continue;
    if (numsToLocs[b].size() != 0) {
      int search = flippedVals ? i - n : i;
      if (!numsToLocs[b].count(search) || numsToLocs[b].size() > 1) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;  
}
