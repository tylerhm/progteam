#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

struct statement
{
    int a;
    int s;
    int align;    
};

bool on(int mask, int pos) { return (mask & (1 << pos)) > 0; }

int bitwiseBrute(int n, vector<statement> statements)
{
    int ret = 0;

    for (int i = 0; i < (1 << n); i++)
    {
        bool valid = true;
        for (int p = 0; p < statements.size(); p++)
        {
            if (!((on(i, statements[p].a) ^ on(i, statements[p].s) ^ statements[p].align)))
            {
                valid = false;
                break;
            }
        }
        if (valid) ret++;
    }
    return ret;
}

int main()
{
    int n; cin >> n;
    vector<statement> statements;
    for (int i = 0; i < n ; i++)
    {
        int N, M; cin >> N >> M;
        statements = vector<statement>();
        for (int j = 0; j < M; j++)
        {
            int a, s; cin >> a >> s;
            int align;
            char x; cin >> x;
            if (x == 'T')
                align = 1;
            else
                align = 0;

            a--;
            s--;
            
            statement st {a, s, align};
            statements.emplace_back(st);
        }
        cout << "Case #" << i + 1 << ": " << bitwiseBrute(N, statements) << "\n";
    }

    return 0;
}
