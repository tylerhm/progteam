#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

template <typename T>
struct BIT {
    vector<T> s;
    int n;
    BIT(int n): s(n + 1), n(n) {}
    void update(int i, T v) {
        for (i++; i <= n; i += i & -i) s[i] += v;
    }
    T query(int i) {
        T ans = 0;
        for (i++; i; i -= i & -i) ans += s[i];
        return ans;
    }
    T query(int l, int r) { return query(r) - query(l - 1); }
    int kth(T k) { // returns n if k > sum of tree
        if (k <= 0) return -1;
        int i = 0;
        for (int pw = 1 << __lg(n); pw; pw >>= 1)
            if (i + pw <= n && s[i + pw] < k) k -= s[i += pw];
        return i;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n_cases; cin >> n_cases;
    for (int iter = 1; iter <= n_cases; iter++)
    {
        ll n; cin >> n;
        vector<int> cardLocs(n);
        ll total = n*(n+1)/2;

        BIT<ll> bit(n);
        for (int i = 0; i < n; i++) {
            int card; cin >> card;
            cardLocs[card-1] = i;
            bit.update(i, card);
        }

        ll ans = 0, lastLoc = 0;
        for (int i = 1; i <= n; i++) {
            ll nextLoc = cardLocs[i-1];
            ll sumStart = min(nextLoc, lastLoc);
            ll sumEnd = max(nextLoc, lastLoc)-1;

            ll cost = bit.query(sumStart, sumEnd);
            ans += min(cost, total - cost);
            bit.update(nextLoc, -i);
            lastLoc = nextLoc;
            total -= i;
        }

        cout << ans << "\n";
    }

    return 0;
}
