#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vector<ll> sides(n);
    for (auto &val : sides) cin >> val;
    sort(all(sides));

    ll total = 0;
    for (int i = 0; i < n-2; i++) {
        ll sideOne = sides[i];

        for (int j = i+1; j < n-1; j++) {
            ll sideTwo = sides[j];
            ll combined = sideOne + sideTwo;

            int maxIndex = j+1;
            while (maxIndex < n && sides[maxIndex] < combined)
                maxIndex++;

            ll setLength = maxIndex - j - 1;
            if (setLength <= 0) continue;
            total += pow(2, setLength) - 1;
        }
    }

    cout << total << "\n";

    return 0;    
}
