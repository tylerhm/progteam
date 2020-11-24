#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

struct player
{
    string name;
    vector<int> scores;
    int totalScore;

    bool operator<(const player& a) const
    {
        if (scores.size() > a.scores.size()) return true;
        if (scores.size() < a.scores.size()) return false;

        if (totalScore > a.totalScore) return true;
        if (totalScore < a.totalScore) return false;

        for (int i = 0; i < scores.size(); i++)
        {
            if (scores[i] > a.scores[i]) return true;
            if (scores[i] < a.scores[i]) return false;
        }

        return (name < a.name);
    }
};

int main()
{
    int n_cases; cin >> n_cases;
    int iter = 1;
    while (n_cases--)
    {
        int n; cin >> n;
        vector<player> players = vector<player>(n);
        for (int i = 0; i < n; i++)
        {
            player p;
            cin >> p.name;
            int size; cin >> size;
            int totalScore = 0;
            vector<int> scores = vector<int>(size);
            for (int j = 0; j < size; j++)
            {
                cin >> scores[j];
                totalScore += scores[j];
            }
            p.scores = scores;
            p.totalScore = totalScore;
            players[i] = p;
        }
        sort(players);
        cout << "Game #" << iter++ << "\n";
        for (player p : players) cout << p.name << "\n";
    }
    return 0;
}
