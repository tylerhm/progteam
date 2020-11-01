#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        int n; cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> nums;
        for (int i = 0; i < n; i++)
        { 
            ll val; cin >> val;
            nums.push(val);
        }
        if (n == 1)
        {
            cout << 0 << "\n";
            continue;
        }
        ll n1, n2, cost;
        n1 = nums.top();
        nums.pop();
        n2 = nums.top();
        nums.pop();
        cost = n1 + n2;
        nums.push(n1 + n2);
        while (!(nums.size() == 1))
        {
            n1 = nums.top();
            nums.pop();
            n2 = nums.top();
            nums.pop();
            cost += n1 + n2;
            nums.push(n1 + n2);
        }
        cout << cost << "\n";
    }
    return 0;
}
