#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n; cin >> n;
    while (n != 0)
    {
        vector<pair<int, string>> cards = vector<pair<int, string>>(n);
        for (int i = 0; i < n; i++) {
            string name; cin >> name;
            int hp; cin >> hp;
            cards[i] = make_pair(hp, name);
        }
        sort(cards);
        for (auto card : cards) cout << card.second << "\n";
        cout << "\n";
        cin >> n;
    }
    return 0;
}
