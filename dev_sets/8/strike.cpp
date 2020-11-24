#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int n;
vector<pair<int, int>> locs;
pair<int, int> t1, t2;
int x1, y1, x2, y2, t;
int maxDeflected;

double pairDist(pair<int, int>& p1, pair<int, int>& p2) {
    return sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}

int missilesDestroyed(double area1)
{
    double area2 = t - area1;

    double r1 = radFromArea(area1);
    double r2 = radFromArea(area2);

    int destroyed = 0;

    for (int i = 0; i < n; i++)
        if (pairDist(t1, locs[i]) <= area1 || pairDist(t2, locs[i]) <= area2)
            destroyed++;
}

double radFromArea(double area)
{
    // A = pi * r^2
    // r^2 = A/PI
    //r = sqrt(A/PI)
    // PI = 3.141 from problem
    return sqrt(area/3.141);
}

int binSearch(double lo, double hi)
{
    while (lo < hi - (0.00001))
    {
        double mid = lo + (hi - lo) / 2;
        int destroyed = missilesDestroyed(mid);

        if (d)
    }
}

int main()
{
    cin >> n;
    while (n != 0)
    {
        locs = vector<pair<int, int>>(n);
        cin >> x1 >> y1 >> x2 >> y2 >> t;
        t1 = make_pair(x1, y1);
        t2 = make_pair(x2, y2);
        for (int i = 0; i < n; i++)
        {
            int x, y; cin >> x >> y;
            locs[i] = make_pair(x, y);
        }

        // binary search on energy given to one tower?? energy to other is total - one???
        maxDeflected = INT_MIN;
        binSearch(0, 100);

        cin >> n;
    }
    return 0;
}
