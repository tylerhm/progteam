#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    while (n != 0) {
        BIT<int> bit(n);
        for (int i = 0; i < n; i++) bit.update(i, 1);

        int cur = 0;
        ll dist = 0;
        int left, right;
        for (int i = 0; i < n; i ++) {
            int next; cin >> next; next--;
            bit.update(next, -1);
            
            // go left
            if (next < cur) left = bit.query(next, cur);
            else left = bit.query(0, cur) + bit.query(next, n - 1);

            // go right
            if (next > cur) right = bit.query(cur, next);
            else right = bit.query(cur, n - 1) + bit.query(0, next);
            
            dist += min(left, right) + 1;
            if (n == 0) dist--;
            
            cur = next;
            if (i < n - 1)
                while (bit.query(cur, cur) == 0) cur = (cur + 1) % n;
                
        }
        
        cout << dist << endl;
        cin >> n;
    }

    return 0;    
}
