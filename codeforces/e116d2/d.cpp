#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j,0,sz(jmp[k]))
                jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b); // or return inf if a == b
        int dep = 31 - __builtin_clz(b - a);
        return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

template<class T>
struct RMinQ {
    vector<vector<T>> jmp;
    RMinQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j,0,sz(jmp[k]))
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b); // or return inf if a == b
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

void solve(int t) {
    int n, m; cin >> n >> m;

    vector<vi> grid(n, vi(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    vector<RMQ<int>> rmax;
    vector<RMinQ<int>> rmin;
    for (int i = 0; i < n; i++) {
        rmax.emplace_back(RMQ<int>(grid[i]));
        rmin.emplace_back(RMinQ<int>(grid[i]));
    }

    int color[n];
    for (int cut = 1; cut < m - 1; cut++) {
        bool valid = true;
        for (int i = 0; i < n; i++) {
            if (rmax[i].query(0, cut) < rmin[i].query(cut, m))
                color[i] = 0;
            else if (rmin[i].query(0, cut) > rmax[i].query(cut, m))
                color[i] = 1;
            else {
                valid = false;
                break;
            }
        }

        if (valid) {
            cout << "YES" << endl;
            for (int c : color) {
                cout << (c == 0 ? 'B' : 'R');
            }

            cout << ' ' << cut << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
        solve(tt);

    return 0;
}

