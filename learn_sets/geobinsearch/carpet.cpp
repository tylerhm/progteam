#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {

}

double solveAngles(vector<double> sides, double S) {
    double sum = 0;
    for (int i = 0; i < 3; i++) {
        double a = sides[i], b = sides[(i+1)%3];
        double term = ((a*a)+(b*b)-(S*S))/(2*a*b);
        if (term < -1 || term > 1) return 100;
        sum += acos(term);
    }
    return sum;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    vector<double> sides(3);
    for (int i = 0; i < 3; i++) cin >> sides[i];

    double lo = 0, hi = sides[0]+sides[2];

    while (true) {
        double S = lo + (hi - lo) / 2;
        double angleSum = solveAngles(sides, S);

        if (angleSum <= 2*M_PI+0.000001 && angleSum >= 2*M_PI-0.000001) {
            cout << S << nl;
            return 0;
        }
        else if (angleSum > 2*M_PI) hi = S;
        else lo = S;
    }


    return 0;
}
