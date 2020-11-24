#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n_cases; cin >> n_cases;
    vector<string> words;
    for (int iter = 1; iter <= n_cases; iter++)
    {
        string word; cin >> word;
        reverse(all(word));
        words.push_back(word);
    }

    sort(all(words));
    for (string w : words)
        cout << w << "\n";

    return 0;
}
