#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

vector<int> L;

void combine(int p, int size, int limit, vector<int> comb) 
{
    // Prune away useless branches.
    if (L.size() - p < limit - size) return;
    if (size == limit) 
    {
        // Do the problem-specific stuff here.
        for (int val : comb)
            cout << val << " ";
        cout << "\n";
        return;
    }
    // Skip L[p].
    combine(p + 1, size, limit, comb);
    // Use L[p] in the combination.
    comb[size] = L[p];
    combine(p + 1, size + 1, limit, comb);
    }

int main()
{
    L = vector<int>();
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);
    L.push_back(4);
    L.push_back(5);
    combine(0, 0, 3, vector<int>(3));
    return 0;
}
