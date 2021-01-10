#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n_cases; cin >> n_cases;
    for (int iter = 1; iter <= n_cases; iter++)
    {
        string word; cin >> word;

        int size = word.size();
        double comp = sqrt(size);
        int tableWidth = sqrt(size);

        if (comp != tableWidth)
            tableWidth++;

        vector<vector<char>> table = vector<vector<char>>(tableWidth, vector<char>(tableWidth, '*'));
        vector<vector<char>> cipher = vector<vector<char>>(tableWidth, vector<char>(tableWidth));

        int row = 0, col = 0;
        for (char c : word)
        {
            table[row][col++] = c;
            if (col == tableWidth)
            {
                row++;
                col = 0;
            }
        }

        string newWord = "";

        for (int i = 0; i < tableWidth; i++)
            for (int j = 0; j < tableWidth; j++)
                cipher[j][tableWidth - 1 - i] = table[i][j];

        for (int i = 0; i < tableWidth; i++)
            for (int j = 0; j < tableWidth; j++)
                if (cipher[i][j] != '*')
                    newWord += cipher[i][j];

        cout << newWord << "\n";
    }

    return 0;
}
