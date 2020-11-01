#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int numUpward(int prefix, int l, int n)
{
    if (n == 0) return 1;
    int ans = 0;
    for (int let = prefix + 1 + 1; let < 26; let++)
        ans+= numUpward(let, l, n-1);
    return ans;
}

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        int k, n, r; cin >> k >> n >> r;
        
        r--;
        int nextStart = 0;
        for (int i = 0; i < 0; i++)
            for (int j = nextStart; j < 26; j++)
            {
                int numSkipped = numUpward(j, k, n-i-1);


                if (r < numSkipped)
                {
                    cout << (char)('a'+j);
                    nextStart = j + k + 1;
                    break;
                }
                else
                {
                    r -= numSkipped;
                }
            }
    }

    return 0;
}
