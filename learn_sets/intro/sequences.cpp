#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> s, s_buff;
    while (n--)
    {
        int l, k; cin >> l >> k;
        s = vector<int>(l);
        for (int i = 0; i < l; i++) cin >> s[i];

        for (int i = 0; i < k; i++)
        {
            s_buff = vector<int>(l-i-1);
            for (int j = 0; j < l-i-1; j++) s_buff[j] = s[j] + s[j+1];
            s = s_buff;
        }

        for (int ans : s_buff) cout << ans << " ";
        cout << "\n";
    }

    return 0;
}
