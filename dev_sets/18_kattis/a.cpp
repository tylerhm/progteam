#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll vecToLL(vector<int> &num) {
  ll ans = 0;
  ll mult = 1;
  for (int i = num.size()-1; i >= 0; i--) {
    ans += num[i] * mult;
    mult *= 10;
  }

  return ans;
}

ll shrink(vector<int> &num) {

  if (num.size() == 1) return 0;

  int index = 0;
  if (num[index] == 1) {
    index++;
    while (num[index] == 0 && index < num.size()) index++;
  }

  if (index == num.size()) return vecToLL(num);
  if (index == 0) {
    num[index] = 1;
    return vecToLL(num);
  }
  num[index] = 0;
  return vecToLL(num);
}

ll grow(vector<int> &num) {
  int index = 0;
  while (num[index] == 9 && index < num.size()) index++;

  if (index == num.size()) return vecToLL(num);
  num[index] = 9;
  return vecToLL(num);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n; cin >> n;
  
  vector<vector<int>> zuesVec(n);
  vector<ll> zuesNum(n);
  for (int i = 0; i < n; i++) {
    string val; cin >> val;
    for (char c : val) zuesVec[i].push_back(c-'0');
    zuesNum[i] = stoll(val);
  }

  // special 0 and n-1
  ll largeFirst = grow(zuesVec[0]);
  if (largeFirst > zuesNum[1]) {
    cout << largeFirst << ' ';
    for (int i = 1; i < n; i++)
      cout << zuesNum[i] << ' ';
    cout << '\n';
    return 0;
  }

  // special 0 and n-1
  ll smallLast = shrink(zuesVec[n-1]);
  if (smallLast < zuesNum[n-2]) {
    for (int i = 0; i < n-1; i++)
      cout << zuesNum[i] << ' ';
    cout << smallLast;
    cout << '\n';
    return 0;
  }

  for (int i = 1; i < n-1; i++) {
    ll left = zuesNum[i-1];
    ll right = zuesNum[i+1];

    // make small first
    ll smallMid = shrink(zuesVec[i]);
    ll largeMid = grow(zuesVec[i]);

    bool found = false;
    if (smallMid < left) {
      zuesNum[i] = smallMid;
      found = true;
    }
    if (largeMid > right) {
      zuesNum[i] = largeMid;
      found = true;
    }

    if (found) {
      for (ll n : zuesNum)
        cout << n << ' ';
      cout << '\n';
      return 0;
    }
  }

  cout << "impossible";
  cout << '\n';
  return 0;
}