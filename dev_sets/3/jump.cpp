#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

vector<int> blocks;
vector<bool> used;
int u, d, cnt;

void permute(int p, vector<int> perm)
{
    if (p == blocks.size())
    {
        cnt++;
        return;
    }

    for (int i = 0; i < blocks.size(); i++)
    {
        if (!used[i])
        {
            int diff = 0;
            if (p != 0)
                diff = blocks[i] - perm[p - 1];
            if (d <= diff && diff <= u)
            {
                used[i] = true;
                perm[p] = blocks[i];
                permute(p + 1, perm);
                used[i] = false;
            }
        }
    }
}

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        int b; cin >> b;
        blocks = vector<int>(b);
        used = vector<bool>(b, false);
        for (int i = 0; i < b; i++) cin >> blocks[i];
        cin >> u >> d;
        d = -d;
        cnt = 0;
        permute(0, blocks);
        cout << cnt << "\n";
    }

    return 0;
}
