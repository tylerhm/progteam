#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    vector<int> t1 = vector<int>(3);
    vector<int> t2 = vector<int>(3);

    for (int i = 0; i < 3; i++) cin >> t1[i];
    for (int i = 0; i < 3; i++) cin >> t2[i];

    sort(all(t1));
    sort(all(t2));

    if (t1 != t2)
    {
        cout << 0 << "\n";
        return 0;
    }

    // construct rectangle and calc diag
    pair<int, int> p1 = make_pair(0, t1[0]);
    pair<int, int> p2 = make_pair(t1[1], 0);

    double dist = sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));

    if (dist != t1[2])
    {
        cout << 0 << "\n";
        return 0;
    }

    cout << 1 << "\n";
    return 0;
}
