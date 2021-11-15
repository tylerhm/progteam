#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P>
vector<pair<P, P>> tangents(P c1, double r1, P c2, double r2) {
	P d = c2 - c1;
	double dr = r1 - r2, d2 = d.dist2(), h2 = d2 - dr * dr;
	if (d2 == 0 || h2 < 0)  return {};
	vector<pair<P, P>> out;
	for (double sign : {-1, 1}) {
		P v = (d * dr + d.perp() * sqrt(h2) * sign) / d2;
		out.push_back({c1 + v * r1, c2 + v * r2});
	}
	if (h2 == 0) out.pop_back();
	return out;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
	cout << fixed << setprecision(9);

	Point<double> s, e, blue, red;
	double br, rr;
	cin >> s.x >> s.y;
	cin >> e.x >> e.y;
	cin >> blue.x >> blue.y >> br;
	cin >> red.x >> red.y >> rr;
	double rc = 2*M_PI*rr;

	auto st = tangents(red, rr, s, 0);
	auto et = tangents(red, rr, e, 0);

	assert(sz(st) == 2);
	assert(sz(et) == 2);

	double bestDist = DBL_MAX;
	for (auto &[b, a] : st) {
		double firstSeg = (b-a).dist();
		for (auto &[c, d] : et) {
			double lastSeg = (d-c).dist();

			// we need arc dist from b-c
			double ba = (b-red).angle();
			double ca = (c-red).angle();
			double bestAng = min(abs(ba-ca), 2*M_PI-abs(ba-ca));

			double ratio = bestAng / (2*M_PI);
			double arclen = ratio*rc;

			bestDist = min(bestDist, firstSeg + arclen + lastSeg);
		}
	}

	cout << bestDist << endl;

    return 0;
}

