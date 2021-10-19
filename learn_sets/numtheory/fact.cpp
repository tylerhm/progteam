#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX_PR = 8000;
int primes[MAX_PR];
void era() {
    for (int i = 1; i < MAX_PR; i++)
        primes[i] = i;
    for (int i = 4; i < MAX_PR; i += 2)
        primes[i] = 2;
    for (int i = 3; i*i < MAX_PR; i++)
        for (int j = i*i; j < MAX_PR; j += i)
            if (primes[j] == j)
                primes[j] = i;
}

vector<map<int, int>> getFactors() {
    era();

    vector<map<int, int>> factors(MAX_PR);
    for (int i = 2; i < MAX_PR; i++) {
        int fac, num = i;
        while (num != 1) {
            fac = primes[num];
            factors[i][fac]++;
            num /= fac;
        }
    }

    return factors;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    auto factors = getFactors();
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        ll val; cin >> val;
        map<int, int> f;
        for (int j = 2; j <= val; j++)
            for (auto [fac, exp] : factors[j])
                f[fac] += exp;
        for (auto [_, exp] : f)
            cout << exp << ' ';
        cout << endl;
    }

    return 0;
}