#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n; cin >> n;
    while (n--)
    {
        string word;
        cin >> word;


        bool valid = true;
        for (int i = 1; i < word.size(); i++)
            if (word[i] <= word[i-1])
            {
                valid = false;
                break;
            }

        if (valid)
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
    }

    return 0;
}
