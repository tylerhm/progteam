#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
int oo = -1^1<<31;
using namespace std;

int main()
{
    int N; cin >> N;

    for (int testCase = 0; testCase < N; testCase++)
    {
        int n; cin >> n;
        int sum = 0, tri = 1;
        for (int k = 1; k <= n; k++)
        {
            tri += k + 1;
            sum += k * tri;
        }
        cout << testCase + 1 << " " << n << " " << sum << "\n";

        // W(n) = SUM[k = 1..n; k*T(k+1)]
    }

    return 0;
}
