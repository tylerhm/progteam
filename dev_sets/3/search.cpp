#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

vector<string> words;
vector<bool> found;
vector<vector<char>> puzzle;
vector<pair<int, int>> dirs = vector<pair<int, int>>();

void search(int row, int col, int wi, int swi, int dir)
{
    if (swi == words[wi].size())
    {
        found[wi] = true;
        return;
    }

    pair<int, int> d = dirs[dir];
    int newR, newC;
    newR = row + d.first;
    newC = col + d.second;

    if (newR >= 0 && newR < puzzle.size() &&
        newC >= 0 && newC < puzzle[newR].size())
        //cout << words[wi].first[words[wi].second] << " " << puzzle[newR][newC] << "\n";
        if (words[wi][swi] == puzzle[newR][newC])
            search(newR, newC, wi, swi+1, dir);
}

int main()
{
    dirs.emplace_back(-1, -1);
    dirs.emplace_back(-1, 0);
    dirs.emplace_back(-1, 1);
    dirs.emplace_back(0, -1);
    dirs.emplace_back(0, 1);
    dirs.emplace_back(1, -1);
    dirs.emplace_back(1, 0);
    dirs.emplace_back(1, 1);

    int n; cin >> n;
    int cur = 1;
    while (n != 0)
    {
        words = vector<string>(n);
        found = vector<bool>(n, false);
        for (int i = 0; i < n; i++) cin >> words[i];

        int r, c; cin >> r >> c;
        puzzle = vector<vector<char>>(r, vector<char>(c));
        for (int row = 0; row < r; row++)
            for (int col = 0; col < c; col++)
                cin >> puzzle[row][col];
        
        for (int row = 0; row < r; row++)
        {
            for (int col = 0; col < c; col++)
            {
                for (int i = 0; i < n; i++)
                {
                    if (!found[i])
                    {
                        if (words[i][0] == puzzle[row][col])
                        {
                            if (words[i].size() == 1)
                                found[i] = true;
                            else
                            {
                                for (int di = 0; di < dirs.size(); di++)
                                {
                                    pair<int, int> d = dirs[di];
                                    int newR, newC;
                                    newR = row + d.first;
                                    newC = col + d.second;

                                    if (newR >= 0 && newR < puzzle.size() &&
                                        newC >= 0 && newC < puzzle[newR].size())
                                        if (words[i][1] == puzzle[newR][newC])
                                            search(newR, newC, i, 2, di);
                                }
                            }
                        }
                    }
                }
            }
        }
        
        bool valid = true;
        for (bool f : found)
        {
            if (!f)
            {
                valid = false;
                break;
            }
        }

        cout << "Puzzle number " << cur++ << ":\n";
        if (valid)
            cout << "ALL WORDS FOUND\n";
        else
            for (int i = 0; i < n; i++)
                if (!found[i])
                    cout << words[i] << "\n";
        cout << "\n";

        cin >> n;
    }
    return 0;
}
