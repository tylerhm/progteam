#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

vector<pair<int, int>> rideLocs;
vector<bool> visited, completed;
vector<vector<double>> dists;
double minDist;

double pairDist(pair<int, int>& p1, pair<int, int>& p2) {
    return sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}

// backtracking bruteforce
double dist(int k, int c)
{
    // not possible
    if (visited[k]) return oo;
    // done
    if (c == visited.size()) return 0;
    visited[k] = true;
    double localMin = oo;
    for (int i = 0; i < dists.size(); i++)
    {
        if (dists[k][i] != -oo); // can't take invalid paths
        {
            double d = dist(i, c+1);
            d += dists[k][i];
            if (d < localMin) localMin = d;
        }
    }
    visited[k] = false;
    return localMin;
}

int main()
{
    int n_cases; cin >> n_cases;
    int iter = 1;
    while (n_cases--)
    {
        int r, b; cin >> r >> b;
        rideLocs = vector<pair<int, int>>(r);
        dists = vector<vector<double>>(r, vector<double>(r));
        visited = vector<bool>(r, false);
        completed = vector<bool>(r, false);
        for (int i = 0; i < r; i++) {
            int x, y; cin >> x >> y;
            rideLocs.push_back(make_pair(x, y));

            // preprocess distances
            for (int j = 0; j <= i; j++) 
            {
                double ld = pairDist(rideLocs[i], rideLocs[j]);
                dists[i][j] = ld;
                dists[j][i] = ld;
            }
        }
        for (int i = 0; i < b; i++) {
            int ii, j; cin >> ii >> j;
            dists[ii-1][j-1] = -oo;
            dists[j-1][ii-1] = -oo;
        }
        double minDist = dist(0, 1);
        cout << "Vacation #" << iter++ << "\n";
        if (minDist != oo)
            printf("Jimmy can finish all of the rides in %.3lf seconds.", minDist + r*120);
        else
            printf("Jimmy should plan this vacation on a different day.");
        cout << "\n\n";
    }
    return 0;
}
