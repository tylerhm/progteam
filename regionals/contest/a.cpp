#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string keys;

ll evalSeconds(string order) {
    int curIndex = 0;
    char curKey = order[curIndex];
    ll seconds = 0;
    rep(i, 0, keys.size()) {
        
        bool found = true;
        int intermediateSeconds = 0;
        while (curKey != keys[i]) {
            if (curIndex == order.size()-1) {
                found = false;
                break;
            }
            intermediateSeconds++;
            curKey = order[++curIndex];
        }

        if (!found) {
            intermediateSeconds = 0;
            while (curKey != keys[i]) {
                intermediateSeconds++;
                curKey = order[--curIndex];
            }
        }
        seconds += intermediateSeconds + 1;
    }

    return seconds;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> keys;

    vector<vector<int>> matrix(10, vector<int>(10, 0));
    for (int i = 1; i < keys.size(); i++) {
        int from = keys[i-1]-'0';
        int to = keys[i]-'0';
        matrix[from][to]++;
        matrix[to][from]++;
    }

    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            cout << i << " and " << j << " have prio " << matrix[i][j] << "\n";
        }
    }
  
    return 0;    
}
