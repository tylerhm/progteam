#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        int n, c; cin >> n >> c;
        int nextBonus = 1;
        int curThreshold = c;
        int score = 0;
        int bonusTemp;
        for (int i = 0; i < n; i++)
        {
            int level; cin >> level;
            score += level;
            if (score >= curThreshold)
            {
                while (score >= curThreshold) curThreshold *= 2;
                score += (curThreshold / 4);
            }
        }
        cout << score << "\n";
    }
    return 0;
}
