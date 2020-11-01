#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;


vector<int> sides;

bool validSide(int s)
{
    int sideLength = sides[s];
    int rest = 0;
    for (int i = 0; i < sides.size(); i++)
    {
        if (i != s)
        {
            rest += sides[i];
            if (rest > sideLength)
                return true;
        }
    }
    return false;
}

int main()
{
    int n_cases; cin >> n_cases;
    for (int c = 0; c < n_cases; c++)
    {
        cout << "Jacuzzi #" << c+1 << ": ";
        int n; cin >> n;
        sides = vector<int>(n);
        for (int i = 0; i < n; i++) cin >> sides[i];
        bool valid = true;
        for (int i = 0; i < n; i++)
        {
            if (!validSide(i))
            {
                cout << "NO" << "\n";
                valid = false;
                break;
            }
        }
        if (valid)
            cout << "YES" << "\n";
    }
    return 0;
}
