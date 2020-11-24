#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string inp; cin >> inp;


    unordered_map<char, int> freq = unordered_map<char, int>();
    for (char c : inp) freq[c]++;

    vector<pair<int, char>> pairs = vector<pair<int, char>>();
    for (auto e : freq) pairs.push_back(make_pair(e.second, e.first));

    sort(all(pairs));
    reverse(all(pairs));

    int ans = 0;
    if (pairs.size() > 2)
        for (int i = 2; i < pairs.size(); i++) ans += pairs[i].first;
    
    cout << ans << "\n";

    return 0;
}
