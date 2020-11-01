#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

void printBoard(vector<int>& board)
{
    for (int i = 0; i < board.size(); i++)
        cout << board[i] << " ";
    cout << "\n";
}

int main()
{
    int n; cin >> n;
    while (n != 0)
    {
        int t; cin >> t;
        int curPlayers = n;
        int curPlayer = 0;
        
        int moves = 0;
        // brute fooorrrceeeee
        vector<int> board = vector<int>(n, 0);
        
        while (true)
        {
            //cout << "starting play with player " << curPlayer << "\n";
            int i;
            curPlayer--;
            for (i = 0; i < t; i++)
            {
                curPlayer++;
                curPlayer %= curPlayers;
                board[curPlayer]++;
            }


            //printBoard(board);

            board.erase(board.begin() + curPlayer);
            curPlayers--;

            //printBoard(board);

            //cout << "ending play with player " << curPlayer << " to start next\n\n";

            // check counts
            int firstVal = board[0];
            bool evenBoard = true;
            for (i = 1; i < curPlayers; i++)
            {
                if (board[i] != firstVal)
                {
                    evenBoard = false;
                    break;
                }
            }
            if (evenBoard)
            {
                cout << board.size() << " " << firstVal << "\n";
                break;
            }
        }

        cin >> n;
    }
    return 0;
}
