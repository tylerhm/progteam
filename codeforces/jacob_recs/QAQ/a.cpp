#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

string s;

bool isQAQ(int a, int b, int c) {
    return (s[a] == 'Q' && s[b] == 'A' && s[c] == 'Q');
}

int main()
{
    cin >> s;
    int sSize = s.size();
    int res = 0;
    for (int i = 0; i < sSize; i++)
        for (int j = i + 1; j < sSize; j++)
            for (int k = j + 1; k < sSize; k++)
                if (isQAQ(i, j, k))
                    res++;
    cout << res << "\n";

    return 0;
}
