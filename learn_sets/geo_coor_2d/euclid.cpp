#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

struct point
{
    double x, y;
    point(double _x, double _y) : x(_x), y(_y) {}

    double dist(point p)
    {
        return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
    }
};

int main()
{

    cout << sin(90) << endl; 
    
    return 0;
    while (true)
    {
        vector<point> parellologram;
        vector<point> triangle;

        for (int i = 0; i < 3; i++)
        {
            double x, y; cin >> x >> y;
            parellologram.emplace_back(x, y);
        }

        for (int i = 0; i < 3; i++)
        {
            double x, y; cin >> x >> y;
            triangle.emplace_back(x, y);
        }

        bool end = true;
        for (auto v : parellologram)
            if (!(v.x == 0 && v.y == 0))
                end = false;
        for (auto v : triangle)
            if (!(v.x == 0 && v.y == 0))
                end = false;
        
        if (end) return 0;

        double triArea = 0.5 * (triangle[0].x * (triangle[1].y - triangle[2].y) +
                                triangle[1].x * (triangle[2].y - triangle[0].y) +
                                triangle[2].x * (triangle[0].y - triangle[1].y));

        double dist12 = parellologram[0].dist(parellologram[1]);
        double dist13 = parellologram[0].dist(parellologram[2]);
        double dist23 = parellologram[1].dist(parellologram[2]);

        double A = acos(((dist12*dist12) + (dist13*dist13) - (dist23*dist23)) /
                          (2 * dist12 * dist13));
        
        double rectHeight = dist12 * sin(A);

        double rectBaseNecessary = triArea / rectHeight;
        double lambdaNecessary = rectBaseNecessary / parellologram[0].dist(parellologram[2]);

        point h = point(parellologram[0].x + lambdaNecessary * (parellologram[2].x - parellologram[0].x),
                        parellologram[0].y + lambdaNecessary * (parellologram[2].y - parellologram[0].y));

        point g = point(h.x + (parellologram[1].x - parellologram[0].x), h.y + (parellologram[1].y - parellologram[0].y));

        printf("%.3lf %.3lf %.3lf %.3lf\n", g.x, g.y, h.x, h.y);
    }

    return 0;
}
