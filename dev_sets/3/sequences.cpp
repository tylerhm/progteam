#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

vector<int> solve(vector<int> nums)
{
    vector<int> ret = vector<int>(nums.size() - 1);

    for (int i = 0; i < nums.size() - 1; i++)
        ret[i] = nums[i] + nums[i+1];
    return ret;
}

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        int n, k; cin >> n >> k;
        vector<int> nums = vector<int>(n);
        for (int i = 0;i < n ;i++) cin >> nums[i];
        while (k--)
            nums = solve(nums);
        for (int i : nums)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
