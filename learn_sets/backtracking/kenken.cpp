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

struct group
{
    char op;
    int ans;
    int curAns;
    vector<pair<int, int>> locations;

    group() {};
};

int n, g;
vector<vector<int>> board;
unordered_map<char, group> charMap;
vector<char> groups;

vector<vector<bool>> usedCols, usedRows, preproc;


void printBoard(int iter)
{
    cout << "KenKen Puzzle #" << iter << ": \n";
        for (auto r : board)
        {
            for (auto v : r)
                cout << v;
            cout << "\n";
        }
        cout << "\n";
}

bool solve(int curGroup, int curSquare, int mustBe)
{
    if (curGroup == groups.size()) return true;
    group g = charMap[groups[curGroup]];
    if (curSquare == g.locations.size()) return solve(curGroup+1, 0, -1);    
    int row = g.locations[curSquare].first;
    int col = g.locations[curSquare].second;
    if (preproc[row][col]) return solve(curGroup, curSquare+1, -1);


    for (int i = 1; i <= n; i++)
    {
        if (usedRows[row][i-1] || usedCols[col][i-1])
            continue;

        // check if this is the first value
        bool valid = false;
        if (curSquare == 0)
        {
            charMap[groups[curGroup]].curAns = i;
            usedRows[row][i-1] = true;
            usedCols[col][i-1] = true;
            board[row][col] = i;
            if (curSquare == g.locations.size() - 1)
            {
                switch (g.op)
                {
                    case ADD:
                        if (solve(curGroup, curSquare+1, ))
                }
            }
            if (solve(curGroup, curSquare+1, -1))
                return true;
            charMap[groups[curGroup]].curAns = 0;
            usedRows[row][i-1] = false;
            usedCols[col][i-1] = false;
        }
        else if (curSquare < g.locations.size() - 2)
        {
            switch (g.op)
            {
                case ADD:
                    if (g.curAns + i < g.ans)
                    {
                        charMap[groups[curGroup]].curAns += i;
                        usedRows[row][i-1] = true;
                        usedCols[col][i-1] = true;
                        board[row][col] = i;
                        if (solve(curGroup, curSquare+1, ))
                            return true;
                        charMap[groups[curGroup]].curAns = 0;
                        usedRows[row][i-1] = false;
                        usedCols[col][i-1] = false;
                    }
                case MUL:
                    if (g.curAns * i < g.ans)
                    {
                        charMap[groups[curGroup]].curAns *= i;
                        usedRows[row][i-1] = true;
                        usedCols[col][i-1] = true;
                        board[row][col] = i;
                        if (solve(curGroup, curSquare+1, -1))
                            return true;
                        charMap[groups[curGroup]].curAns /= i;
                        usedRows[row][i-1] = false;
                        usedCols[col][i-1] = false;
                    }
            }
        }
        else
        {
            switch (g.op)
            {
                case ADD:
                    if (g.curAns + i == g.ans)
                    {
                        charMap[groups[curGroup]].curAns += i;
                        usedRows[row][i-1] = true;
                        usedCols[col][i-1] = true;
                        board[row][col] = i;
                        if (solve(curGroup, curSquare+1))
                            return true;
                        charMap[groups[curGroup]].curAns = 0;
                        usedRows[row][i-1] = false;
                        usedCols[col][i-1] = false;
                    }
                case SUB:
                    if (abs(g.curAns - i) == g.ans)
                    {
                        int oldAns = charMap[groups[curGroup]].curAns;
                        charMap[groups[curGroup]].curAns = g.ans;
                        usedRows[row][i-1] = true;
                        usedCols[col][i-1] = true;
                        board[row][col] = i;
                        if (solve(curGroup, curSquare+1))
                            return true;
                        charMap[groups[curGroup]].curAns = oldAns;
                        usedRows[row][i-1] = false;
                        usedCols[col][i-1] = false;
                    }
                case MUL:
                    if (g.curAns * i == g.ans)
                    {
                        charMap[groups[curGroup]].curAns *= i;
                        usedRows[row][i-1] = true;
                        usedCols[col][i-1] = true;
                        board[row][col] = i;
                        if (solve(curGroup, curSquare+1))
                            return true;
                        charMap[groups[curGroup]].curAns /= i;
                        usedRows[row][i-1] = false;
                        usedCols[col][i-1] = false;
                    }
                case DIV:
                    if ((double)g.curAns / i == g.ans || (double)i / g.curAns == g.ans)
                    {
                        int oldAns = charMap[groups[curGroup]].curAns;
                        charMap[groups[curGroup]].curAns = g.ans;
                        usedRows[row][i-1] = true;
                        usedCols[col][i-1] = true;
                        board[row][col] = i;
                        if (solve(curGroup, curSquare+1))
                            return true;
                        charMap[groups[curGroup]].curAns = oldAns;
                        usedRows[row][i-1] = false;
                        usedCols[col][i-1] = false;
                    }
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

        usedCols = vector<vector<bool>>(n, vector<bool>(n, false));
        usedRows = vector<vector<bool>>(n, vector<bool>(n, false));
        preproc = vector<vector<bool>>(n, vector<bool>(n, false));

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

            if (charMap[c].op == NON)
            {
                int row = charMap[c].locations[0].first;
                int col = charMap[c].locations[0].second;

                board[row][col] = ans;
                preproc[row][col] = true;
                usedRows[row][ans] = true;
                usedCols[col][ans] = true;
            }
        }

        solve(0, 0);
        printBoard(iter++);

        cin >> n;
    }
    

    return 0;
}
