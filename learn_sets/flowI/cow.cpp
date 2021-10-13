#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

struct FordFulkerson {
    int n, source, sink;
    vector<vector<int>> cap;
    FordFulkerson(int size) : n(size + 2), source(n - 2), sink(n - 1), cap(vector<vector<int>>(n, vector<int>(n, 0))) {}
    void add(int v, int u, int c) {
        cap[v][u] = c;
    }
    void conSource(int v, int c) {
        cap[source][v] = c;
    }
    void conSink(int v, int c) {
        cap[v][sink] = c;
    }
    int ff() {
        vector<bool> seen(n, false);
        int flow = 0;

        // find all aug paths
        while (true) {
            // run dfs
            fill(all(seen), false);
            int res = dfs(source, seen, oo);
            if (res == 0) break;
            flow += res;
        }
        return flow;
    }
    int dfs(int v, vector<bool> &seen, int minF) {
        if (v == sink) return minF;
        if (seen[v]) return 0;
        seen[v] = true;
        int flow = 0;
        for (int i = 0; i < n; i++) {
            if (cap[v][i] > 0)
                flow = dfs(i, seen, min(cap[v][i], minF));
            if (flow > 0) {
                cap[v][i] -= flow;
                cap[i][v] += flow;
                return flow;
            }
        }
        return 0;
    }
};

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
        double angle() const { return atan2(y, x); }
        P unit() const { return *this/dist(); } // makes dist()=1
        P perp() const { return P(-y, x); } // rotates +90 degrees
        P normal() const { return perp().unit(); }
        P rotate(double a) const {
                return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
        friend ostream& operator<<(ostream& os, P p) {
                return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P> bool onSegment(P s, P e, P p) {
        return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template<class P> vector<P> segInter(P a, P b, P c, P d) {
        auto oa = c.cross(d, a), ob = c.cross(d, b),
     oc = a.cross(b, c), od = a.cross(b, d);
        // Checks if intersection is single non-endpoint point.
        if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
                return {(a * ob - b * oa) / (ob - oa)};
        set<P> s;
        if (onSegment(c, d, a)) s.insert(a);
        if (onSegment(c, d, b)) s.insert(b);
        if (onSegment(a, b, c)) s.insert(c);
        if (onSegment(a, b, d)) s.insert(d);
        return {all(s)};
}

struct segment {
        Point<int> a, b;
        segment(Point<int> a, Point<int> b) : a(a), b(b) {}
        bool inter(segment &o) {
                return segInter(a, b, o.a, o.b).size();
        }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n_cases; cin >> n_cases;
    for (int iter = 1; iter <= n_cases; iter++)
    {
        int n; cin >> n;
        vector<segment> vertical, horizontal;
        for (int i = 0; i < n; i++)
        {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
                        Point<int> one(x1, y1);
                        Point<int> two(x2, y2);
            // vert
            if (y2 - y1 == 0)
                horizontal.emplace_back(one, two);
            // hori
            else
                vertical.emplace_back(one, two);
        }
        FordFulkerson g(n);
        // solve with bipartite matching
        // setup sources
        for (int i = 0; i < horizontal.size(); i++)
            g.conSource(i, 1);
        for (int i = 0; i < vertical.size(); i++)
            g.conSink(horizontal.size() + i, 1);

        for (int i = 0; i < horizontal.size(); i++)
            for (int j = 0; j < vertical.size(); j++)
                                if (horizontal[i].inter(vertical[j]))
                    g.add(i, horizontal.size() + j, 1);

        cout << n - g.ff() << "\n";
    }

    return 0;
}