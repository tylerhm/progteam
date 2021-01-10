#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

vector<int> vectorized;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string inp; cin >> inp;

    if (inp.size() % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }
    
    for (char c : inp) vectorized.push_back(c - '0');

    

    return 0;
}