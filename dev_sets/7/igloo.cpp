#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int v, t;

double hemiVolume(double rad)
{
    return ((double)4/(double)3)*M_PI*pow(rad, 3)/2;
}

bool isPossible(double outerRad)
{
    if (outerRad <= outerRad - t) return true;
    return (hemiVolume(outerRad) - hemiVolume(outerRad - t) <= v);
}

double binSearch(double lo, double hi)
{
    double mid;
    while (hi - lo > 0.000001)
    {
        mid = lo + (hi - lo) / (double)2;
        if (isPossible(mid))
        {
            lo = mid;
            continue;
        }
        else
        {
            hi = mid;
            continue;
        }
    }
    mid = lo + (hi - lo) / (double)2;
    return mid;
}

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        cin >> v >> t;
        printf("%.3lf\n", binSearch((double)0, (double)10000));
    }
    return 0;
}
