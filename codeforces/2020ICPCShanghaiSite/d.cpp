#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

long double n, p1, v1, p2, v2;
long double EPSILON = 0.00000001;

bool leftRightDist(long double t) {
    long double xtl = v1*(t-p1/v1);
    long double xtr = n-(v2*(t-(n-p2)/v2));
    if (xtl < 0) return xtr <= 0;
    if (xtr > n) return xtl >= n;
    return xtl >= xtr;
}
bool leftLeftDist(long double t) {
    long double d1 = p1+n;
    long double d2 = p2+n;
    long double xt1 = v1*t;
    long double xt2 = v2*t;
    return xt1 >= d1 || xt2 >= d2;
}
bool rightRightDist(long double t) {
    long double d1 = n-p1+n;
    long double d2 = n-p2+n;
    long double xt1 = v1*t;
    long double xt2 = v2*t;
    return xt1 >= d1 || xt2 >= d2;
}
bool rightLeftDist(long double t) {
    long double xtr = n-(v1*(t-(n-p1)/v1));
    long double xtl = v2*(t-p2/v2);
    return (xtr <= n && xtl >= 0) || (xtr <= 0 || xtl >= n);
}

void solve(int t) {
    cin >> n >> p1 >> v1 >> p2 >> v2;

    if (p1 > p2) {
        long double temp = p1;
        p1 = p2;
        p2 = temp;
        temp = v1;
        v1 = v2;
        v2 = temp;
    }

    long double minTime = oo;

    // lr
    long double lo = 0, hi = 2*n/max(v1, v2), mid;
    while (hi-lo > EPSILON) {
        mid = lo+(hi-lo)/2;
        if (leftRightDist(mid)) {
            minTime = min(minTime, mid);
            hi = mid;
        }
        else lo = mid;
    }
    lo = 0; hi = 2*n/max(v1, v2);
    while (hi-lo > EPSILON) {
        mid = lo+(hi-lo)/2;
        if (leftLeftDist(mid)) {
            minTime = min(minTime, mid);
            hi = mid;
        }
        else lo = mid;
    }
    lo = 0; hi = 2*n/max(v1, v2);
    while (hi-lo > EPSILON) {
        mid = lo+(hi-lo)/2;
        if (rightRightDist(mid)) {
            minTime = min(minTime, mid);
            hi = mid;
        }
        else lo = mid;
    }
    lo = 0; hi = 2*n/max(v1, v2);
    while (hi-lo > EPSILON) {
        mid = lo+(hi-lo)/2;
        if (rightLeftDist(mid)) {
            minTime = min(minTime, mid);
            hi = mid;
        }
        else lo = mid;
    }
    cout << fixed << setprecision(10) << minTime << endl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tt; cin >> tt;
    for (int t = 1; t <= tt; t++)
        solve(t);

    return 0;
}
