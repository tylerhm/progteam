#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    string cases; getline(cin, cases);
    stringstream s(cases);
    int n_cases; s >> n_cases;
    int iter = 1;
    while (n_cases--)
    {
        string inp; getline(cin, inp);
        vector<int> freq = vector<int>(26, 0);
        for (char c : inp)
        {
            if (c < 97)
                c += 32;
            freq[c-'a']++;
        }

        cout << "Case " << iter++ << ":";
        cout << " a=" << freq[0];
        cout << " e=" << freq[4];
        cout << " i=" << freq[8];
        cout << " o=" << freq[14];
        cout << " u=" << freq[20];

        cout << "\n";
    }
    return 0;
}
