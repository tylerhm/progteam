#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<string> curFood;
int idx;
vector<string> food;
int len;

vector<vector<string>> ans;

void getSubsets(int index, int included) {
    if (included == len) {
        ans.push_back(curFood);
        return;
    }
    if (index == food.size()) return;

    getSubsets(index + 1, included);

    curFood[idx++] = food[index];
    getSubsets(index + 1, included + 1);
    idx--;
}

void solve(int t) {
    int n; cin >> n >> len;
    food.resize(n);
    curFood.resize(len);
    ans.clear();
    for (auto &x : food) cin >> x;
    idx = 0;
    sort(all(food));
    getSubsets(0, 0);
    reverse(all(ans));
    for (auto a : ans) {
        for (string f : a) cout << f << ' ';
        cout << endl;
    }
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 0; tt < t; tt++) solve(t);
}