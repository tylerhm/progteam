#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    string s; cin >> s;
    vector<ll> cumSum = vector<ll>(s.size());
    cumSum[0] = (s[0] == s[1]? 1 : 0);
    for (int i = 1; i < s.size() - 1; i++)
        cumSum[i] = cumSum[i-1] + (s[i] == s[i+1]? 1 : 0);
    cumSum[s.size()-1] = cumSum[s.size()-2];
    int m; cin >> m;
    while (m--) {
        int l, r; cin >> l >> r;
        cout << cumSum[r-2] - (((l-2) < 0)? 0 : cumSum[l-2]) << "\n";
    }

    return 0;
}
