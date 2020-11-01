#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

void permute(int p, vector<bool> used, vector<int> perm) {
    if (p == used.size()) 
    {
        // Do something problem-specific with perm here.
        for (int val : perm)
            cout << val << " ";
        cout << "\n";
        return;
    }
    // Try every unused element in the current position.
    for (int i = 0; i < used.size(); i++) 
    {
            if (!used[i]) 
            {
            used[i] = true;
            perm[p] = i;
            permute(p + 1, used, perm);
            used[i] = false;
        }
    }
}

int main()
{
    vector<int> toBePermed = vector<int>();
    toBePermed.push_back(1);
    toBePermed.push_back(2);
    toBePermed.push_back(3);
    toBePermed.push_back(4);
    toBePermed.push_back(5);
    permute(0, vector<bool>(5, false), toBePermed);
    return 0;
}
