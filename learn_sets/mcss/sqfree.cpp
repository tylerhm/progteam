#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

vector<int> numSquaresBelow = vector<int>(1000001);

void populateNumSquaresBelow()
{
    numSquaresBelow[0] = 0;
    int base = 1;
    int lastSq = 1;
    while (lastSq <= 1000000) {
        int nextSq = base*base;

        numSquaresBelow[lastSq] = numSquaresBelow[lastSq-1] + 1;
        for (int i = lastSq + 1; i <= 1000000 && i < nextSq; i++) numSquaresBelow[i] = numSquaresBelow[i - 1];
        base++;
        lastSq = nextSq;
    }

}

int main()
{
    populateNumSquaresBelow();
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        int l, h; cin >> l >> h;
        if (l > 0) cout << ((h-l+1) - (numSquaresBelow[h] - numSquaresBelow[l-1]));
        else cout << ((h-l+1) - numSquaresBelow[h]);
        cout << "\n";
    }
    return 0;
}
