#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

#define MAX_PPL 16

int n;
int maxHappiness;
vector<vector<pair<bool, char>>> adjMatrix;
vector<bool> matched;
int curHappiness;

void bruteHappiness(int p)
{
    if (p >= MAX_PPL)
    {
        if (curHappiness > maxHappiness)
            maxHappiness = curHappiness;
        return;
    }
    if (matched[p])
    {
        bruteHappiness(p + 1);
        return;
    }

    for (int i = 0; i < MAX_PPL; i++)
    {
        if (i == p || matched[i]) continue;

        matched[p] = true;
        matched[i] = true;

        int happiness;
        if (adjMatrix[p][i].second == 'L' && adjMatrix[i][p].second == 'L')
            happiness = 4;
        else if (adjMatrix[p][i].second >= 'L' && adjMatrix[i][p].second >= 'L')
            happiness = 3;
        else if ((adjMatrix[p][i].first && adjMatrix[p][i].second >= 'L') ||
                 (adjMatrix[i][p].first && adjMatrix[i][p].second >= 'L'))
            happiness = 2;
        else if ((!adjMatrix[p][i].first && adjMatrix[p][i].second >= 'L') ||
                 (!adjMatrix[i][p].first && adjMatrix[i][p].second >= 'L'))
            happiness = 1;
        else
            happiness = 0;

        curHappiness += happiness;

        bruteHappiness(p + 1);

        matched[p] = false;
        matched[i] = false;
        curHappiness -= happiness;
    }
    // option where we just skip this persons relationships
    bruteHappiness(p + 1);
}

int main()
{
    cin >> n;
    int iter = 1;
    while (n != 0)
    {
        adjMatrix = vector<vector<pair<bool, char>>>(MAX_PPL, vector<pair<bool, char>>(MAX_PPL, make_pair(false, '.')));
        matched = vector<bool>(MAX_PPL, false);
        int curIndex = 0;

        vector<string> rels = vector<string>(n);
        unordered_map<char, int> personToIndex = unordered_map<char, int>();

        for (int i = 0; i < n; i++)
        {
            cin >> rels[i];
            char from = rels[i][0];
            char to = rels[i][2];
            if (personToIndex.find(from) == personToIndex.end())
                personToIndex[from] = curIndex++;
            if (personToIndex.find(to) == personToIndex.end())
                personToIndex[to] = curIndex++; 
        }

        for (int i = 0; i < n; i++)
        {
            string inp = rels[i];
            int from = personToIndex[inp[0]];
            char rel = inp[1];
            int to = personToIndex[inp[2]];
            adjMatrix[from][to].first = isupper(from);
            adjMatrix[from][to].second = rel;
        }

        maxHappiness = 0;
        curHappiness = 0;
        bruteHappiness(0);
        cout << "Party " << iter++ << " has a maximum happiness quotient of " << maxHappiness << "\n";

        cin >> n;
    }
    return 0;
}
