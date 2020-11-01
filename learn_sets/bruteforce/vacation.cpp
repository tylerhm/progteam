#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

vector<pair<int, int>> rideLocs;
vector<vector<bool>> available;
double minDist;

double pairDist(pair<int, int>& p1, pair<int, int>& p2) {
    return sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}

void permute(int p, vector<bool>& used, vector<int>& perm) {
    if (p == perm.size()) {
        double dist = 0;
        for (int i = 0; i < perm.size()-1; i++)
            dist += pairDist(rideLocs[perm[i]], rideLocs[perm[i+1]]);
        if (dist < minDist)
            minDist = dist;
        return;
    }
    for (int i = 0; i < perm.size(); i++) {
        if (!used[i]) {
            if (i > 0 && available[i][perm[p-1]]) {
                used[i] = true;
                perm[p] = i;
                permute(p + 1, used, perm);
                used[i] = false;
            }
        }
    }
}

int main()
{
    int n_cases; cin >> n_cases;
    int iter = 1;
    while (n_cases--)
    {
        int r, b; cin >> r >> b;
        rideLocs = vector<pair<int, int>>(r);
        available = vector<vector<bool>>(r, vector<bool>(r, true));
        for (int i = 0; i < r; i++) {
            int x, y; cin >> x >> y;
            rideLocs.push_back(make_pair(x, y));
        }
        for (int i = 0; i < b; i++) {
            int ii, j; cin >> ii >> j;
            available[ii-1][j-1] = false;
        }
        minDist = oo;
        vector<bool> used = vector<bool>(r, false);
        vector<int> perm = vector<int>(r);

        permute(0, used, perm);
        double ans = minDist + r*120;
        printf("Vacation #%d: %.3lf\n", iter++, ans);
    }
    return 0;
}
