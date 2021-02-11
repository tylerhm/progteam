#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

double loc(double a, double b, double c) {
    double num = c*c-a*a-b*b;
    double denom = -2.0*a*b;
    return acos(num/denom);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(3);

    double a, b, c; cin >> a >> b >> c;

    double lo = max(abs(a-b), max(abs(b-c), abs(a-c)));
    double hi = min(a+b, min(b+c, a+c));

    double ans = -oo;
    // 750 trials for depth
    for (int trial = 0; trial < 250; trial++) {
        double mid = (lo + hi) / 2.0;
        double an = loc(a, b, mid) + loc(b, c, mid) + loc(a, c, mid);

        // update running answer
        if (abs(an - 2*M_PI) < 0.000001)
            ans = mid;
        
        if (an <= 2*M_PI)
            lo = mid;
        else
            hi = mid;
    }

    if (ans != -oo)
        cout << ans*ans*(sqrt(3)/(double)4) << nl;
    else
        cout << -1.000 << nl;


    return 0;
}