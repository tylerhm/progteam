#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

vector<int> boxes;
int n, k;

bool possible(int maxWeight)
{
    int sum = 0;
    int boxesNecessary = 1;
    
    for (int i = 0; i < n; i++)
    {
        if (boxes[i] > maxWeight)
            return false;
        sum += boxes[i];
        if (sum > maxWeight)
        {
            sum = boxes[i];
            boxesNecessary++;
            if (boxesNecessary > k)
                return false;
        }
    }

    return true;
}

int binSearch(int lo, int hi)
{
    if (hi == lo + 1)
    {
        if (possible(lo))
            return lo;
        else if (possible(hi))
            return hi;
        return -1;
    }
    if (hi >= lo)
    {
        int mid = lo + (hi - lo) / 2;

        //cout << mid << " is " << (possible(mid)? "possible" : "not possible") << "\n";

        if (possible(mid))
            return binSearch(lo, mid);
        else
            return binSearch(mid, hi);
    }
    return -1;
}

int main()
{
    cin >> n >> k;
    boxes = vector<int>(n);
    int sum = 0;
    for (int i = 0; i < n; i++) 
    {
        cin >> boxes[i];
        sum += boxes[i];
    }
    cout << binSearch(0, sum) << "\n";

    return 0;
}
