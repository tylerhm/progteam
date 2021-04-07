#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define TEST_CASES 1'000
#define SAMPLE_CASES 3

int RANDOM_CASES = TEST_CASES - SAMPLE_CASES;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cout << "Generating data..." << endl;

    ofstream in("piano.in");

    // Print num tests
    in << TEST_CASES << "\n";

    // Print sample data
    in << "EEFGGFEDCCDEEDDEEFGGFEDCCDEDCC" << "\n";
    in << "EDCDEEEDDDEGGEDCDEEEEDDEDC" << "\n";
    in << "CAB" << "\n";

    // Custom cases
    int MAX_LEN = 1000;
    int KEY_LEN = 7;

    srand(time(NULL));
    for (int i = 0; i < RANDOM_CASES; i++) {

        cout << "Making case #" << i << endl;
        
        int len = (rand() % 1000) + 1;

        string song = "";
        for (int j = 0; j < len; j++)
            song += 'A' + (rand() % KEY_LEN);
        
        in << song << "\n";
    }

    in.close();

    cout << "Done!\n";

    return 0;    
}
