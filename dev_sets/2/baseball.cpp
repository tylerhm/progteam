#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

struct Player
{
    string first;
    string last;
    
    double ba;
    double obp;
    double sp;

    bool operator<(const Player& a) const
    {
        if (ba != a.ba)
            return ba > a.ba;
        if (obp != a.obp)
            return obp > a.obp;
        return sp > a.sp;
    }
};

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int p; cin >> p;
        vector<Player> players;
        while(p--)
        {
            string first;
            string last;
            int hits = 0;
            int walks = 0;
            int appearances = 0;
            int bases = 0;
            int bats = 0;
            cin >> last >> first >> appearances;

            for (int j = 0; j < appearances; j++)
            {
                string data; cin >> data;
                if (data[0] >= '0' && data[0] <= '9') // hit
                {
                    bats++;
                    hits++;
                    bases += data[0] - '0';
                }
                else if (data == "HR")
                {
                    bats++;
                    hits++;
                    bases += 4;
                }
                else if (data == "BB")
                {
                    walks++;
                }
                else if (data == "K" || data == "GO" || data == "FO")
                    bats++;
            }
            Player p {first, last, ((double)hits)/bats, ((double)hits+walks)/appearances, ((double)bases)/bats};
            players.emplace_back(p);
        }
        sort(players);
        cout << "Season #" << i+1 << ":\n";
        for (Player player : players) cout << player.last << ", " << player.first << "\n"; //<< player.ba << " " << player.obp << " " << player.sp << "\n";
        cout << "\n";
    }

    return 0;
}
