#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vector<string> grid(n);

    for (int i = 0; i < n; i++) cin >> grid[i];


    for (int i = 0; i < n; i++) {
        int black = 0;
        int white = 0;
        char runcolor = 'B';
        int run = 0;
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'B') {

                if (runcolor == 'B')
                    run++;
                else {
                    run = 1;
                    runcolor = 'B';
                }

                black++;

                if (run >= 3) {
                    cout << 0 << endl;
                    return 0;
                }
            }

            if (grid[i][j] == 'W') {

                if (runcolor == 'W')
                    run++;
                else {
                    run = 1;
                    runcolor = 'W';
                }

                white++;
                
                if (run >= 3) {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }

        if (black != white) {
            cout << 0 << endl;
            return 0;
        }
    }

    for (int j = 0; j < n; j++) {
        int black = 0;
        int white = 0;
        char runcolor = 'B';
        int run = 0;
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == 'B') {

                if (runcolor == 'B')
                    run++;
                else {
                    run = 1;
                    runcolor = 'B';
                }

                black++;

                if (run >= 3) {
                    cout << 0 << endl;
                    return 0;
                }
            }

            if (grid[i][j] == 'W') {

                if (runcolor == 'W')
                    run++;
                else {
                    run = 1;
                    runcolor = 'W';
                }

                white++;
                
                if (run >= 3) {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }

        if (black != white) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << 1 << endl;

    return 0;
}
