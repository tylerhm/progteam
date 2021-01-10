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
    string garb; getline(cin, garb);
    for (int iter = 1; iter <= n_cases; iter++)
    {
        string inp;
        getline(cin, inp);

        if (inp.size() < 10 || inp.substr(0, 10) != "Simon says")
            continue;
        
        cout << inp.substr(10) << "\n";
    }

    return 0;
}
