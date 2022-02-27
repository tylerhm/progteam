#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int getVal(char c) {
    if (c - '0' <= 9) return c - '0';
    return c - 'A' + 10;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string line;
    while (getline(cin, line)) {
        for (int i = 0; i < sz(line); i += 2) {
            int tens = getVal(line[i]);
            int ones = getVal(line[i+1]);
            cout << (char)(tens * 16 + ones);
        }
        cout << endl;
    }

    return 0;
}

