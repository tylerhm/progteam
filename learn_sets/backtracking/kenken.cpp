#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

#define NON '.'
#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'

#define NAN -1

struct group
{
    char op;
    int ans;
    int curAns;
    vector<pair<int, int>> locations;
};

int n, g;
vector<vector<int>> board;
unordered_map<char, group> charMap;
vector<char> groups;

vector<bool> usedCols, usedRows;

bool solve(int curGroup, int curSquare)
{
    group g = charMap[groups[curGroup]];
    if (curGroup == groups.size()) return true;
    if (curSquare == g.locations.size()) return solve(curGroup+1, 0);

    int row = g.locations[curSquare].first;
    int col = g.locations[curSquare].second;
    for (int i = 1; i <= n; i++)
    {
        if (usedRows[row] || usedCols[col])
            continue;

        // check if this is the first value
        bool valid = false;
        if (curSquare == 0)
        {
            charMap[groups[curGroup]].curAns = i;
            usedRows[row] = true;
            usedCols[col] = true;
            if (solve(curGroup, curSquare+1))
                return true;
            usedRows[row] = false;
            usedCols[col] = false;
        }
        else
        {
            switch (g.op)
            {
                case ADD:
                    if (g.curAns + i <= g.ans)
                    {
                        
                    }
                case SUB:
                case MULT:
                case DIV:
            }
        }
    }
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> n;
    int iter = 1;
    while (n != 0)
    {
        cin >> g;
        board = vector<vector<int>>(n, vector<int>(n, 0));
        charMap = unordered_map<char, group>();
        groups = vector<char>(g);

        usedCols = vector<bool>(n, false);
        usedRows = vector<bool>(n, false);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char c; cin >> c;
                if (charMap.find(c) == charMap.end())
                {
                    groups[charMap.size()] = c;
                    charMap[c] = group();
                }
                charMap[c].locations.push_back(make_pair(i, j));
            }
        }

        for (int i = 0; i < g; i++)
        {
            char c; cin >> c;
            int ans; cin >> ans;
            char op; cin >> op;

            charMap[c].ans = ans;
            charMap[c].op = op;
        }

        solve();
        cout << "KenKen Puzzle #" << iter++ << ": \n";
        for (auto r : board)
        {
            for (auto v : r)
                cout << v;
            cout << "\n";
        }
        cout << "\n";

        cin >> n;
    }
    

    return 0;
}
