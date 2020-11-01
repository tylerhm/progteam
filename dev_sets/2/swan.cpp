#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

struct location {
    double x;
    double y;
};

location toCartesian(int r, int degree)
{
    double theta = degree * (M_PI / 180);
    location loc {r*cos(theta), r*sin(theta)};
    return loc;
}

double getDist(location l1, location l2)
{
    double x = l2.x - l1.x;
    double y = l2.y - l1.y;
    return sqrt((x*x)+(y*y));
}

vector<location> locations;
int n;
double shortest;

void permute(int p, vector<bool>& used, vector<int>& perm) {
    if (p == n) {
        double dist = getDist(locations[0], locations[perm[0]+1]);
        for (int i = 0; i < n - 1; i++)
            dist += getDist(locations[perm[i]+1], locations[perm[i+1]+1]);
        dist += getDist(locations[perm[n-1]+1], locations[0]);
        shortest = min(shortest, dist);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            perm[p] = i;
            permute(p + 1, used, perm);
            used[i] = false;
        }
    }
}

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        int k, a, s; cin >> k >> a >> s;
        n = k;
        locations = vector<location>(k+1);
        locations[0] = toCartesian(1000, a);
        for (int i = 1; i <= k; i++) {
            int d, al; cin >> d >> al;
            locations[i] = toCartesian(d, al);
        }
        vector<bool> used = vector<bool>(k, false);
        vector<int> perm = vector<int>(k);
        shortest = oo;
        permute(0, used, perm);
        double time = shortest / s;
        printf("%.2f\n", time);
    }
    
    return 0;
}
