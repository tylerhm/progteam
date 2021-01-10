#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n; cin >> n;
    vector<int> seq(n), types(n, 0);
    for (int i = 0; i < n; i++) cin >> seq[i];
    int intimidation = 0;
    for (int i = 1; i < n - 1; i++) {
        if (seq[i] > seq[i-1] && seq[i] > seq[i+1]) {
            types[i] = 1;
            intimidation++;
        }
        else if (seq[i] < seq[i-1] && seq[i] < seq[i+1]){
            types[i] = -1;
            intimidation++;
        }
    }
    // look for hill valley hill
    bool change = false;
    for (int i = 1; i < n - 1; i++) {
        if (types[i-1] == 1 && types[i] == -1 && types[i+1] == 1 ||
            types[i-1] == -1 && types[i] == 1 && types[i+1] == -1) {
            change = true;
            intimidation -= 3;
            break;
        }
    }
    // look for hill valley or valley hill
    if (!change) {
        for (int i = 0; i < n - 1; i++) {
            if (types[i] == 1 && types[i+1] == -1 ||
                types[i] == -1 && types[i+1] == 1) {
                change = true;
                intimidation -= 2;
                break;
            }
        }
    }
    if (!change && intimidation > 0) intimidation--;
    cout << intimidation << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tt; cin >> tt;
    for (int t = 1; t <= tt; t++)
        solve(t);

    return 0;
}
