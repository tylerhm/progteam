#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define TEST_CASES 10
#define SAMPLE_CASES 2
#define CUSTOM_CASES 3

int RANDOM_CASES = TEST_CASES - SAMPLE_CASES - CUSTOM_CASES;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cout << "Generating data..." << endl;

    ofstream in("badminton.in");

    // Print num tests
    in << TEST_CASES << "\n";

    // Print sample data
    in << "A 5 5" << "\n";
    in << "1 1 1 1 1" << "\n";
    in << "B 10 3" << "\n";
    in << "5 7 2 7 3 3 10 5 11 5" << "\n";

    // Print custom cases
    in << "A 4 1" << "\n";
    in << "1 2 2 1" << "\n";
    in << "A 1 1" << "\n";
    in << "2" << "\n";
    in << "A 10 1" << "\n";
    in << "1 2 1 2 1 2 1 2 1 2" << "\n";

    int MAX_ROUNDS = (int)10e6;
    int MAX_SCORE = (int)100;
    int MAX_VOLLEY = (int)10e9;

    int RANDOM_EXIT_CHANCE = 10000;

    // Custom cases
    srand(time(NULL));
    for (int i = 0; i < RANDOM_CASES; i++) {

        cout << "Making case #" << i << endl;

        char serve = 'A' + (rand() % 2);
        vector<int> rounds; 
        int win_score = (rand() % MAX_SCORE) + 1;


        char curServe = serve;
        ll scoreA = 0, scoreB = 0;
        vector<ll> volleys;
        while (true) {
            int hits = (rand() % MAX_VOLLEY) + 1;
            rounds.push_back(hits);
            bool serverWon = hits&1;

            if (serverWon) {
                if (curServe == 'A')
                    scoreA++;
                else
                    scoreB++;                
            } else {
                if (curServe == 'A')
                    curServe = 'B';
                else
                    curServe = 'A';
            }

            // Break if the game is over
            if (scoreA >= win_score && scoreA >= scoreB + 2)
                break;
            if (scoreB >= win_score && scoreB >= scoreA + 2)
                break;

            // Random chance to stop early, because Bob and Alice are stupid
            if (!(rand() % RANDOM_EXIT_CHANCE))
                break;
        }

        in << serve << " " << rounds.size() << " " << win_score << "\n";
        in << rounds[0];
        for (int j = 1; j < rounds.size(); j++) in << " " << rounds[j];
        in << "\n";
    }

    in.close();

    cout << "Done!\n";

    return 0;    
}
