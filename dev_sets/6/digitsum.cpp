#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n; cin >> n;
    while (n != 0)
    {
        vector<int> nums = vector<int>(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        sort(nums);

        vector<int> num1 = vector<int>(7, 0);
        vector<int> num2 = vector<int>(7, 0);

        // calc num zeros
        int nonzeros = 0;
        while (nums[nonzeros] == 0) nonzeros++;

        
        // do some initialization
        int remaining = n;
        if (!(remaining % 2))
        {
            num1[(--remaining) / 2] = nums[nonzeros];
            num2[(--remaining) / 2] = nums[nonzeros + 1];
        }
        else
        {
            num2[(--remaining) / 2] = nums[nonzeros];
            num1[(--remaining) / 2] = nums[nonzeros + 1];
        }

        for (int i = 0; i < n; i++)
        {
            if (i < nonzeros || i > nonzeros + 1)
            {
                if (!(remaining%2))
                    num1[(--remaining)/2] = nums[i];
                else
                    num2[(--remaining)/2] = nums[i];
            }
        }

        // calculate their sums
        int ans = 0;
        int mult = 1;
        int base = 10;
        for (int i = 0; i < 7; i++)
        {
            ans += mult * (num1[i] + num2[i]);
            mult *= base;
        }
        cout << ans << "\n";

        cin >> n;
    }
    return 0;
}
