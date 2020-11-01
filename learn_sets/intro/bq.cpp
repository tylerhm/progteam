#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int c; cin >> c;
    unordered_set<string> names;
    string name;
    while (c--)
    {
        names.clear();
        int n, s; cin >> n >> s;
        for (int i = 0; i < n; i++)
        { 
            cin >> name;
            names.insert(name);
        }
        int trial;
        for (trial = 0; trial < s; trial++)
        {
            if (names.size() == 1)
                break;
            cin >> name;
            names.erase(name);
        }
        for (int i = trial; i < s; i++) cin >> name;
        cout << *names.begin() << " " << trial << "\n";
    }

    return 0;
}
