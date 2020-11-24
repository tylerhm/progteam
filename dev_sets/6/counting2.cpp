#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n_cases; cin >> n_cases;
    int iter = 1;
    string garbage; getline(cin, garbage);
    while (n_cases--)
    {
        string inp; getline(cin, inp);
        vector<int> alphabet = vector<int>(26, 0);
        for (char c : inp)
        {
            if (c < 97)
                c += 32;

            if (c >= 97 && c <= 122)
                alphabet[c-'a']++;
        }
        cout << "Case " << (iter++) << ":";
        cout << " a=" << alphabet[0];
        cout << " e=" << alphabet[4];
        cout << " i=" << alphabet[8];
        cout << " o=" << alphabet[14];
        cout << " u=" << alphabet[20] << "\n";
    }
    return 0;
}
