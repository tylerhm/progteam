#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    vector<int> f1 = vector<int>(26, 0);
    vector<int> f2 = vector<int>(26, 0);

    string s1, s2;
    cin >> s1 >> s2;
    int i = 1;
    while(s1 != "END" && s2 != "END")
    {
        fill(f1, 0);
        fill(f2, 0);

        for (char s : s1)
            f1[s-'a']++;
        for (char s : s2)
            f2[s-'a']++;

        bool valid = true;
        for (int i = 0; i < 26; i++)
        {
            if (f1[i] != f2[i])
            {
                valid = false;
                break;
            }
        }

        cout << "Case " << i++ << ": ";
        if (valid)
            cout << "same" << "\n";
        else
            cout << "different" << "\n";
        cin >> s1 >> s2;
    }

    return 0;
}
