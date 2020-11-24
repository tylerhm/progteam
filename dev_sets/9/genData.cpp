#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

#define POINTS 100000
#define S_EXCLUSIVE 1000000000

struct pair_hash
{
    inline size_t operator()(const pair<int,int> & v) const
    {
        return v.first*31+v.second;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    FILE * ifp = fopen("testData.txt", "w");

    fprintf(ifp, "%d %d\n", POINTS, S_EXCLUSIVE-1);

    unordered_set<pair<int, int>, pair_hash> seenPoints;

    for (int i = 0; i < POINTS; i++)
    {
        int randX = rand() % S_EXCLUSIVE;
        int randY = rand() % S_EXCLUSIVE;
        pair<int, int> p = make_pair(randX, randY);

        if (seenPoints.find(p) == seenPoints.end())
        {
            seenPoints.insert(p);
            fprintf(ifp, "%d %d\n", randX, randY);
        }
        else
            i--;
    }

    fclose(ifp);

    return 0;
}
