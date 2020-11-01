#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int n;
vector<vector<ll>> dist = vector<vector<ll>>();

void floyds()
{
    for (int p = 0; p < n; p++)
        for (int s = 0; s < n; s++)
            for (int d = 0; d < n; d++)
                if (dist[s][p] + dist[p][d] < dist[s][d])
                    dist[s][d] = dist[s][p] + dist[p][d];
}

int main()
{
    return 0;
}
