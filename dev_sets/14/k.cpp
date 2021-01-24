#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

map<char, int> alph;

struct word {
    string w;
    word(string w) : w(w) {}
    bool operator<(word a) {
        int minL = min(a.w.size(), w.size());
        for (int i = 0; i < minL; i++) {
            if (alph[w[i]] < alph[a.w[i]]) return true;
            if (alph[a.w[i]] < alph[w[i]]) return false;
        }
        return (w.size() < a.w.size());
    }
};

void solve(int n, int t) {
    string inp; cin >> inp;
    for (int i = 0; i < inp.size(); i++)
        alph[inp[i]] = i;
    
    vector<word> words;
    for (int i = 0; i < n; i++) {
        string w; cin >> w;
        words.emplace_back(w);
    }

    sort(all(words));

    cout << "year " << t << nl;
    for (word w : words) {
        cout << w.w << nl;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    int iter = 1;
    while (n != 0) {
        solve(n, iter++);
        cin >> n;
    }

    return 0;
}
