#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n; cin >> n;
    
    int switchWins = 0, stayWins = 0;
    for (int iter = 1; iter <= n; iter++)
    {
        int winningDoor = rand() % 3;
        int randoDoor = rand() % 3;

        if (randoDoor == winningDoor)
            stayWins++;
        else
            switchWins++;
    } 

    cout << "Wins by switching:\t" << switchWins << "\n";
    cout << "Switch win chance:\t" << ((double)switchWins / n * 100) << "\n";
    cout << "Wins by staying:  \t" << stayWins << "\n";
    cout << "Stay win chance:  \t" << ((double)stayWins / n * 100) << "\n";

    return 0;
}
