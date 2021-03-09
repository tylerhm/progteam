#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool adjDigits(ll num) {
    ll lastDigit = -1;
    while (num > 0) {
        ll digit  = num % 10;
        num /= 10;
        if (digit == lastDigit) {
            return true;
        }
        lastDigit = digit;
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll count = 0;
    ll upper; cin >> upper;
    for (ll num = 1; num <= upper; num++) {
        if (!adjDigits(num)) {
            //cout << num << "\n";
            count++;
        }
    }
    
    cout << count << "\n";

    return 0;    
}
