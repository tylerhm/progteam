#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    unordered_map<string, int> votes = unordered_map<string, int>();
    int n; cin >> n;

    int maxVote = INT_MIN;
    vector<string> maxVotes = vector<string>();
    for (int i = 0; i < n; i++)
    {
        string inp; cin >> inp;
        votes[inp]++;

        if (votes[inp] > maxVote)
        {
            maxVotes.clear();
            maxVotes.push_back(inp);
            maxVote = votes[inp];
        }
        else if (votes[inp] == maxVote)
            maxVotes.push_back(inp);
    }
    sort(maxVotes);
    for (string max : maxVotes) cout << max << "\n";

    return 0;
}
