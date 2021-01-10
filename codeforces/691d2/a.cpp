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
    for (int iter = 1; iter <= n_cases; iter++)
    {
        int n; cin >> n;
        string n1, n2; cin >> n1 >> n2;
        ll r = 0, b = 0;

        for (int i = 0; i < n; i++) {
            if (n1[i] > n2[i]) r++;
            else if (n2[i] > n1[i]) b++;
        }

        if (r == b) cout << "EQUAL";
        else if (r > b) cout << "RED";
        else cout << "BLUE";
        cout << "\n";
    }

    return 0;
}
