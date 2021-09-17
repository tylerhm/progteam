#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, d;
vector<int> days;
vector<ll> pay;

ll maxPay;

void allSubsets(int index, int curDays, int curPay) {
    if (index == n) return;
    
    allSubsets(index + 1, curDays, curPay);

    if (curDays + days[index] <= d) {
        maxPay = max(maxPay, curPay + pay[index]);
        allSubsets(index + 1, curDays + days[index], curPay + pay[index]);
    }
}

void solve(int t) {
    cin >> n >> d;
    days.resize(n);
    pay.resize(n);
    for (int i = 0; i < n; i++) {
        int d, p; cin >> d >> p;
        days[i] = d;
        pay[i] = p;
    }

    maxPay = 0;
    allSubsets(0, 0, 0);

    cout << maxPay << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 0; tt < t; tt++) solve(t);

    return 0;    
}
