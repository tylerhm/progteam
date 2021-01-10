#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

ll carrylessmulti(ll a)
{
    ll base = 10, mult;
    vector<ll> sums;
    ll top = a;
    ll bigMult = 1;
    while (top > 0) {
        int curTopDig = top % 10;
        top /= 10;

        ll bot = a;
        mult = 1;
        ll curVal = 0;
        while (bot > 0) {
            int curBotDig = bot % 10;
            bot /= 10;

            curVal += (curBotDig * curTopDig % 10) * mult;
            mult *= 10;
        }
        sums.push_back(curVal * bigMult);
        bigMult *= base;
    }

    ll ans = 0;
    bool hasVals = true;
    mult = 1;
    while (hasVals)
    {
        hasVals = false;
        ll curDigit = 0;
        for (int i = 0; i < sums.size(); i++)
        {
            if (sums[i] == 0)
                continue;
            hasVals = true;
            curDigit += sums[i] % 10;
            curDigit = curDigit % 10;
            sums[i] /= 10;
        }
        ans += curDigit * mult;
        mult *= base;
    }

    return ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll min = 0;
    ll max = 9999999999999;

    unordered_map<ll, int> lookup;

    //FILE output = fopen("bruteforce.txt", "w");
    for (ll test = min; test <= max; test++) {
        cout << carrylessmulti(test) << "\n";
    }

    return 0;
}
