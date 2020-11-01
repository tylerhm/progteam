#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

void subsets(int p, vector<bool> in) {
    if (p == in.size()) 
    {
        for (bool a : in)
            cout << a << " ";
        cout << "\n";
        // The array ’in’ represents our subset.
        // Do something problem-specific here, maybe print it.
        return;
    }
    // L[p] is not in the subset.
    in[p] = false;
    subsets(p + 1, in);
    // L[p] is in the subset.
    in[p] = true;
    subsets(p + 1, in);
}


// Check if the bit at index pos is on in mask.
bool on(int mask, int pos) { return (mask & (1 << pos)) > 0; }

void subsetsBitStyle(vector<int> in)
{
    // mask will iterate through all 2^N subsets.
    for(int mask = 0; mask < (1 << in.size()); mask++) 
    {
        // Do something problem-specific with the subset. Here I’ll just
        // print it.
        for(int k = 0; k < in.size(); k++) 
            if(on(mask, k)) 
                cout << in[k] << " ";
        cout << "\n";
    }
}

int main()
{
    subsets(0, vector<bool>(5, false));
    vector<int> toBeSubseted = vector<int>();
    toBeSubseted.push_back(1);
    toBeSubseted.push_back(2);
    toBeSubseted.push_back(3);
    toBeSubseted.push_back(4);
    toBeSubseted.push_back(5);
    subsetsBitStyle(toBeSubseted);
    return 0;
}
