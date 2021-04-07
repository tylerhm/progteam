#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

double tf, vf, hf, td, vd, hd;
double timeTillFrisbeeHitsGround;

double getTimeInFlight(double t) {
    double timeInFlight = min(timeTillFrisbeeHitsGround, t - tf);
    if (timeInFlight < 0) timeInFlight = 0;
    return timeInFlight;
}

double getFrisbeeX(double timeInFlight) {
    return timeInFlight * vf;
}

double getFrisbeeY(double timeInFlight) {
    double frisbeeY = hf - timeInFlight * timeInFlight / 2;
    if (frisbeeY < 0) frisbeeY = 0;
    return frisbeeY;
}

double getTimeDog(double t) {
    double dogTime = t - td;
    if (dogTime < 0) dogTime = 0;
    return dogTime;
}

double getMinTime(double frisbeeY, double frisbeeX) {
    double minTimeNeededY = (sqrt(6 * hd) - sqrt(6 * hd - 6 * frisbeeY)) / 3;
    double minTimeNeededX = frisbeeX / vd;
    return max(minTimeNeededY, minTimeNeededX);
}

bool valid(double t) {
    if (t < td) return false;

    double timeInFlight = getTimeInFlight(t);
    double frisbeeX = getFrisbeeX(timeInFlight);
    double frisbeeY = getFrisbeeY(timeInFlight);

    if (frisbeeY > hd) return false;

    double timeMovedDog = getTimeDog(t);
    double minTimeNeeded = getMinTime(frisbeeY, frisbeeX);

    return timeMovedDog >= minTimeNeeded;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cout << fixed;
    cout << setprecision(10);

    cin >> tf >> vf >> hf >> td >> vd >> hd;

    timeTillFrisbeeHitsGround = sqrt(2 * hf);

    // binary search for t
    double lo = 0, hi = DBL_MAX;
    while (abs(hi - lo) > 0.00001) {
        double mid = lo + (hi - lo) / 2;
        if (valid(mid)) hi = mid;
        else lo = mid + 0.000001;
    }
    double t = lo;

    double timeInFlight = getTimeInFlight(t);
    double fisbeeX = getFrisbeeX(timeInFlight);

    cout << t + fisbeeX / vd << "\n";

    return 0;    
}
