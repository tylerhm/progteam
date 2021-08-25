#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <typename T>
struct BIT
{
    vector<T> s;
    int n;
    BIT(int n) : s(n + 1), n(n) {}
    void update(int i, T v)
    {
        for (i++; i <= n; i += i & -i)
            s[i] += v;
    }
    T query(int i)
    {
        T ans = 0;
        for (i++; i; i -= i & -i)
            ans += s[i];
        return ans;
    }
    T query(int l, int r) { return query(r) - query(l - 1); }
    int kth(T k)
    { // returns n if k > sum of tree
        if (k <= 0)
            return -1;
        int i = 0;
        for (int pw = 1 << __lg(n); pw; pw >>= 1)
            if (i + pw <= n && s[i + pw] < k)
                k -= s[i += pw];
        return i;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    while (n != 0)
    {
        BIT<int> bit(n);
        for (int i = 0; i < n; i++)
            bit.update(i, 1);

        // drop first ball
        int prev; cin >> prev; prev--;
        bit.update(prev, -1);
        ll dist = 1;
        for (int i = 1; i < n; i++) {
            // get next ball
            int current; cin >> current; current--;

            int left = min(prev, current), right = max(prev, current);

            // find the min of through and around
            int through = bit.query(left, right);
            int around = bit.query(left) + bit.query(right, n - 1);

            int best = min(through, around);
            
            // move to the location
            dist += best;

            // drop the ball
            dist++;
            bit.update(current, -1);

            // find the next valid location for the ball
            int nextLoc = bit.kth(bit.query(current) + 1);
            if (nextLoc == n) nextLoc = bit.kth(1);

            prev = current;
            current = nextLoc;
        }

        cout << dist << endl;
        cin >> n;
    }

    return 0;
}
