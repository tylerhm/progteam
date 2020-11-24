#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n; cin >> n;
    vector<string> s1 = vector<string>(n);
    vector<string> s2 = vector<string>(n);

    for (int i = 0; i < n; i++) cin >> s1[i];
    for (int i = 0; i < n; i++) cin >> s2[i];

    unordered_set<string> s = unordered_set<string>();

    int curSize = 1;
    for (int i = 0; i < n; i++)
    {
        auto s1l = s.find(s1[i]);
        if (s1l == s.end())
            s.insert(s1[i]);
        else
            s.erase(s1l);
        auto s2l = s.find(s2[i]);
        if (s2l == s.end())
            s.insert(s2[i]);
        else
            s.erase(s2l);
        if (s.size() == 0)
        {
            cout << curSize << "\n";
            curSize = 0;
        }
        curSize++;
    }

    if (curSize != 1)
        cout << curSize-1 << "\n";

    return 0;
}
