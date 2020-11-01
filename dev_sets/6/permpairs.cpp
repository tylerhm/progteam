#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int fact(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

int numPerms(string s)
{
    int l = s.size();

    vector<int> freq = vector<int>(26, 0);
    for (char c : s)
        freq[c-'a']++;

    int factorial =1;
    for (int i = 0; i < 26; i++)
        factorial *= fact(freq[i]);

    return fact(l) / factorial;
}

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        int k; cin >> k;
        string a; cin >> a;

        int numPermys = numPerms(a);

        int i1 = k;
        int i2 = numPermys-k;

        bool swapped = false;
        if (i2 < i1)
        {
            int t = i1;
            i1 = i2;
            i2 = t;
            swapped = true;
        }

        string p1, p2;

        sort(a);
        for (int i = 0; i < i1; i++) next_permutation(a.begin(), a.end());
        if (swapped)
            p2 = a;
        else
            p1 = a;
        for (int i = i1; i < i2-1; i++) next_permutation(a.begin(), a.end());
        if (swapped)
            p1 = a;
        else
            p2 = a;
        cout << p1 << " " << p2 << "\n";
    }
    return 0;
}
