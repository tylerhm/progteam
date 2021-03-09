#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool same(pair<char, int> a, pair<char, int> b) {
  return (a.first == '?' ||
          b.first == '?' ||
          a.first == b.first && a.second == b.second);
}

void computeLPS(vector<pair<char, int>> &pat, int m, vector<int> &lps) {
  int len = 0;
  int i = 1;
  lps[0] = 0;

  while (i < m) {
    if (same(pat[i], pat[len])) {
      len++;
      lps[i] = len;
      i++;
    }
    else {
      if (len != 0)
        len = lps[len - 1];
      else
        lps[i++] = len;
    }
  }
}

int kmpSearch(vector<pair<char, int>> &pat, vector<pair<char, int>> &txt) {
  int m = pat.size();
  int n = txt.size();

  vector<int> lps(m);
  int j = 0;

  computeLPS(pat, m, lps);

  int i = 0, res = 0, next_i = 0;

  while (i < n) {
    if (same(pat[j], txt[i])) {
      j++;
      i++;
    }
    if (j == m) {
      j = lps[j - 1];
      res++;

      if (lps[j] != 0)
        i = ++next_i;
      j = 0;
    }
    else if (i < n && !same(pat[j], txt[i])) {
      if (j != 0)
        j = lps[j - 1];
      else
        i++;
    }
  }
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m; cin >> n >> m;
  vector<pair<char, int>> large(n), small(m);
  for (int i = 0; i < n; i++) {
    char dir; cin >> dir;
    large[i].first = dir;
    if (dir == '?') continue;
    int w; cin >> w;
    large[i].second = w;
  }
  for (int i = 0; i < m; i++) {
    char dir; cin >> dir;
    small[i].first = dir;
    if (dir == '?') continue;
    int w; cin >> w;
    small[i].second = w;
  }

  cout << kmpSearch(small, large) << endl;

  return 0;  
}
