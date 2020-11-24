#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int iters;
void binSearch(int lo, int hi, int search)
{
    iters++;
    int mid = ceil(((double)hi + lo) / 2.00);

    if (mid == search) return;

    if (mid < search) return binSearch(mid + 1, hi, search);
    return binSearch(lo, mid - 1, search);
}

int main()
{
    int n_cases; cin >> n_cases;
    for (int iter = 1; iter <= n_cases; iter++)
    {
        int a, b, x; cin >> a >> b >> x;
        iters = 0;
        binSearch(a, b, x);
        cout << "Game #" << iter << ": " << iters << " guess" << ((iters > 1) ? "es\n" : "\n");
    }
    return 0;
}
