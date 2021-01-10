#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

char bases[] = { '\0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0' };

unordered_map<char, int> charToMinBase = {
    {'0', 1},
    {'1', 2},
    {'2', 3},
    {'3', 4},
    {'4', 5},
    {'5', 6},
    {'6', 7},
    {'7', 8},
    {'8', 9},
    {'9', 10},
    {'a', 11},
    {'b', 12},
    {'c', 13},
    {'d', 14},
    {'e', 15},
    {'f', 16},
    {'g', 17},
    {'h', 18},
    {'i', 19},
    {'j', 20},
    {'k', 21},
    {'l', 22},
    {'m', 23},
    {'n', 24},
    {'o', 25},
    {'p', 26},
    {'q', 27},
    {'r', 28},
    {'s', 29},
    {'t', 30},
    {'u', 31},
    {'v', 32},
    {'w', 33},
    {'x', 34},
    {'y', 35},
    {'z', 36},
};

unordered_map<char, int> charToBase = {
    {'0', 0},
    {'1', 1},
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    {'a', 10},
    {'b', 11},
    {'c', 12},
    {'d', 13},
    {'e', 14},
    {'f', 15},
    {'g', 16},
    {'h', 17},
    {'i', 18},
    {'j', 19},
    {'k', 20},
    {'l', 21},
    {'m', 22},
    {'n', 23},
    {'o', 24},
    {'p', 25},
    {'q', 26},
    {'r', 27},
    {'s', 28},
    {'t', 29},
    {'u', 30},
    {'v', 31},
    {'w', 32},
    {'x', 33},
    {'y', 34},
    {'z', 35},
};

void tokenize(string const &str, vector<string> &out)
{
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(" ", end)) != std::string::npos)
    {
        end = str.find(" ", start);
        out.push_back(str.substr(start, end - start));
    }
}

bool validExpression(string &p1, char &op, string &p2, string &p3, int &base)
{
    double p1b10 = 0, p2b10 = 0, p3b10 = 0;

    int mul = 1;
    for (int i = p1.size() - 1; i >= 0; i--)
    {
        p1b10 += mul * (charToBase[p1[i]]);
        mul *= base;
    }
    mul = 1;
    for (int i = p2.size() - 1; i >= 0; i--)
    {
        p2b10 += mul * (charToBase[p2[i]]);
        mul *= base;
    }
    mul = 1;
    for (int i = p3.size() - 1; i >= 0; i--)
    {
        p3b10 += mul * (charToBase[p3[i]]);
        mul *= base;
    }

    switch (op)
    {
        case '+':
            //cout << "Trying " << p1b10 << " + " << p2b10 << " == " << p3b10 << "\n";
            return p1b10 + p2b10 == p3b10;
        case '-':
            //cout << "Trying " << p1b10 << " - " << p2b10 << " == " << p3b10 << "\n";
            return p1b10 - p2b10 == p3b10;
        case '*':
            //cout << "Trying " << p1b10 << " * " << p2b10 << " == " << p3b10 << "\n";
            return p1b10 * p2b10 == p3b10;
        case '/':
            //cout << "Trying " << p1b10 << " / " << p2b10 << " == " << p3b10 << "\n";
            return p1b10 / p2b10 == p3b10;
    }
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n_cases; cin >> n_cases;
    string garb; getline(cin, garb);
    for (int iter = 1; iter <= n_cases; iter++)
    {
        string line; getline(cin, line);
        vector<string> parts;
        tokenize(line, parts);

        char op = parts[1][0];

        string p1 = parts[0];
        string p2 = parts[2];
        string p3 = parts[4];


        int minBase = 0;
        bool isUnary = true;
        for (char c : p1)
        {
            if (c != '1')
                isUnary = false;
            if (charToMinBase[c] > minBase)
                minBase = charToMinBase[c];
        }
        for (char c : p2)
        {
            if (c != '1')
                isUnary = false;
            if (charToMinBase[c] > minBase)
                minBase = charToMinBase[c];
        }
        for (char c : p3)
        {
            if (c != '1')
                isUnary = false;
            if (charToMinBase[c] > minBase)
                minBase = charToMinBase[c];
        }

        if (isUnary)
            minBase--;

        bool foundAns = false;
        for (int i = minBase; i <= 36; i++)
            if (validExpression(p1, op, p2, p3, i))
            {
                cout << bases[i];
                foundAns = true;
            }

        if (!foundAns)
            cout << "invalid";

        cout << "\n";
    }

    return 0;
}
