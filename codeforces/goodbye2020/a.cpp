#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

// Heron's
// Area = sqrt(p(p-a)(p-b)(p-c))
// p = a+b+c/2

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void solve(int t) {
    int n; cin >> n;
    vector<int> trees(n);
    for (int i=0; i<n; i++) cin >> trees[i];

    set<ll> areas;

    for (int i = 0; i < n; i++) {
        double a, b, c;
        a = distance(0, 1, trees[i], 0);
        for (int j = i + 1; j < n; j++) {
            b = trees[j] - trees[i];
            c = distance(0, 1, trees[j], 0);
            double p = (a+b+c)/2.0;
            double area = p * (p-a) * (p-b) * (p-c);
            ll normalized = area * 10000;
            if (normalized%10 == 9) normalized++;
            areas.insert(normalized);
        }
    }
    
    cout << areas.size() << nl;
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
