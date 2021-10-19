#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <typename T>
struct FastMatExpo {
    ll n, m;
    vector<vector<T>> scalar, mult, ident, res;
    FastMatExpo(vector<vector<T>> _scalar, vector<vector<T>> _mult, ll _m) 
    { scalar = _scalar; mult = _mult; n = scalar.size(); m = _m; createIdent(); }
    void createIdent() {
        ident = vector<vector<T>>(n, vector<T>(n, 0));
        for (int i = 0; i < n; i++) ident[i][i] = 1;
    }
    vector<vector<T>> modPow(ll pow) { return res = applyMod(fastPow(scalar, pow)); }
    vector<vector<T>> fastPow(vector<vector<T>> mat, ll pow) {
        mat = applyMod(mat);
        if (pow==0) return ident;
        if (pow==1) return mat;
        if (pow&1) return matMult(mat, fastPow(mat, pow-1));
        return applyMod(fastPow(matMult(mat, mat), pow/2));
    }
    vector<vector<T>> matMult(vector<vector<T>> mat1, vector<vector<T>> mat2) {
        vector<vector<T>> res(n, vector<T>(n, (T)0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    res[i][j] = (res[i][j] + ((mat1[i][k] * mat2[k][j]) % m)) % m;
        return applyMod(res);
    }
    vector<vector<T>> applyMod(vector<vector<T>> mat) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] %= m;
        return mat;
    }
    ll getAns(int idx) {
        ll ans = 0;
        for (int i = 0; i < n; i++)
            ans = (ans + ((res[idx][i] * mult[i][0]) % m)) % m;
        return ans;
    }

    void printMat() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << res[i][j] << ' ';
            cout << endl;
        }
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<vector<ll>> scalar = {
        {1, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 0},
        {0, 0, 1, 1, 1, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {1, 2, 3, 4, 5, 1},
    };

    vector<vector<ll>> mult = {
        {1},
        {1},
        {1},
        {1},
        {1},
        {5}
    };
    FastMatExpo<ll> fme = FastMatExpo<ll>(scalar, mult, (ll)1000000007);

    ll n;
    while ((cin >> n)) {
        fme.modPow(n-1);
        cout << fme.getAns(5) << endl;
    }

    return 0;
}
