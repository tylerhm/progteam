#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void printSet(set<int> s) {
  for (int x : s) cout << x+1 << ' ';
  cout << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n; cin >> n;
  vector<int> arr(n);
  rep(i, 0, n) {
    int x; cin >> x;
    arr[i] = --x;
  }

  // Calc child array.
  vector<int> child(n);
  rep(i, 0, n) child[arr[i]] = i;

  // Find first sort.
  set<int> sortOne;
  rep(i, 0, n/4) {
    sortOne.insert(i);
    sortOne.insert(child[i]);
  }

  int others = 0;
  while (sortOne.size() < n/2) sortOne.insert(others++);

  vector<int> sortableOne;
  for (auto idx : sortOne) sortableOne.push_back(arr[idx]);
  sort(all(sortableOne));

  // Apply first sort.
  // Jacob iterator trick! woo
  auto it = sortOne.begin();
  rep(i, 0, n/2) {
    arr[*it] = sortableOne[i];
    it++;
  }

  // Recalc children.
  rep(i, 0, n) child[arr[i]] = i;

  // Find second sort.
  set<int> sortTwo;
  rep(i, n/4, n/2) {
    sortTwo.insert(i);
    sortTwo.insert(child[i]);
  }

  others = 0;
  while (sortTwo.size() < n/2) sortTwo.insert(others++);

  vector<int> sortableTwo;
  for (auto idx : sortTwo) sortableTwo.push_back(arr[idx]);
  sort(all(sortableTwo));

  // Apply second sort.
  // Jacob iterator trick! woo
  it = sortTwo.begin();
  rep(i, 0, n/2) {
    arr[*it] = sortableTwo[i];
    it++;
  }

  // Find third sort.
  set<int> sortThree;
  rep(i, n/2, n) {
    sortThree.insert(i);
  }

  cout << 3 << '\n';
  printSet(sortOne);
  printSet(sortTwo);
  printSet(sortThree);

  return 0;  
}
