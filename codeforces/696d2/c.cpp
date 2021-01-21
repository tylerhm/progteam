#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

void solve(int t) {
    int n; cin >> n;
    n *= 2;
    vector<int> numV(n);
    map<int, int> nums;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        nums[num]++;
        numV[i] = num;
    }
    sort(all(nums), greater<int>());
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
