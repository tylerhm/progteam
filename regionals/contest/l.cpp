#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 998244353

vector<ll> prefix;

void precomp() {
    prefix = vector<ll>(10e5);
    prefix[0] = 1;
    ll powNine = 9;
    for (ll i = 1; i < 10e5; i++) {
        prefix[i] = (prefix[i-1] + powNine) % MOD;
        powNine = ((powNine * 9) % MOD) % MOD;
    }
}

ll getNum(string &val, int index, int prev) {
    if (index == val.size()) return 0;
    ll ans = 0;
    ll digitPossible = (val[index]-'0') + 1;
    if (prev <= val[index]-'0') digitPossible--;
    ans += (digitPossible * prefix[val.size() - index - 1]) % MOD;
    return (ans + getNum(val, index+1, val[index]-'0')) % MOD;
}

string subOne(string val, int index) {
    if (val[index] == '0') {
        val[index] = '9';
        if (index == 0)
            return val.substr(1);
        return subOne(val, index-1);
    }
    val[index]--;
    return val;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    precomp();
    string L, U; cin >> L >> U;
    L = subOne(L, L.size()-1);

    ll lowerBound = getNum(L, 0, -1);
    ll upperBound = getNum(U, 0, -1);

    cout << upperBound << ' ' << lowerBound << "\n";
    cout << upperBound-lowerBound << "\n";

    return 0;    
}
