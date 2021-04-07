#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll cases; cin >> cases;
    for (ll i = 0; i < cases; i++) {
        char curServe; cin >> curServe;
        ll rounds, win_score; cin >> rounds >> win_score;
        ll scoreA = 0, scoreB = 0;

        for (ll i = 0; i < rounds; i++) {
            ll hits; cin >> hits;
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

            if (scoreA >= win_score && scoreA >= scoreB + 2)
                break;
            if (scoreB >= win_score && scoreB >= scoreA + 2)
                break;
        }
        
        cout << scoreA << "-" << scoreB << endl;
    }

    return 0;    
}