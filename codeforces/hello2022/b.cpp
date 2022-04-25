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
    int n; cin >> n;
    vector<tuple<int, int, int>> data(n);
    for (auto &[s, e, c] : data) cin >> s >> e >> c;
    int minIdx = 0, maxIdx = 0;
    cout << get<2>(data[0]) << nl;
    for (int i = 1; i < n; i++) {
        auto &[ns, ne, nc] = data[i];
        auto &[mis, mie, mic] = data[minIdx];
        auto &[mas, mae, mac] = data[maxIdx];

        if (ns < mis || (ns == mis && nc < mic))
            minIdx = i;

        if (ne > mae || (ne == mae && nc < mac))
            maxIdx = i;

        auto &[nmis, nmie, nmic] = data[minIdx];
        auto &[nmas, nmae, nmac] = data[maxIdx];

        if (nmis <= nmas && nmie >= nmae) maxIdx = minIdx;
        else if (nmas <= nmis && nmae >= nmie) minIdx = maxIdx;

        if (minIdx == maxIdx) cout << get<2>(data[minIdx]) << nl;
        else cout << get<2>(data[minIdx]) + get<2>(data[maxIdx]) << nl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++)
      solve();

    return 0;
}

