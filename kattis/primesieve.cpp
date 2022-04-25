#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <list>
#include <numeric>
#include <random>
#include <tuple>
#include <map>
#include <set>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int LIM = 1e8;
int n;
int primes;
bitset<LIM + 1> isPrime;
void comp(int n) {
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for (int i = 4; i <= LIM; i += 2)
        isPrime[i] = false;
    for (int i = 3; i*i <= LIM; i += 2) if (isPrime[i])
        for (int j = 2*i; j <= LIM; j += i)
            isPrime[j] = false;
    for (int i = 2; i <= n; i++)
        if (isPrime[i]) primes++;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int q; cin >> n >> q;
    comp(n);
    cout << primes << "\n";
    while (q--) {
        int x; cin >> x;
        cout << isPrime[x] << "\n";
    }

    return 0;
}

