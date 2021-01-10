#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    unordered_map<char, int> freq;
    string s; cin >> s;
    for (char c : s) freq[c-'a']++;
    
    ll ans = 1;
    for (auto e : freq) {
        ans *= ((e.second + 1) % 11092019);
        ans %= 11092019;
    }

    cout << ans << endl;

    return 0;
}
