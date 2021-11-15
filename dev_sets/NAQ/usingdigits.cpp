#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

vector<vector<int>> tiles, memo;
string key;
int xs, ys;
int minSteps;

bool valid(int x, int y) {
    return x >= 0 && x < xs && y >= 0 && y < ys;
}

void solve(int x, int y, int keyIdx, int curSum) {
    if (x == xs-1 && y == 0) {
        minSteps = min(minSteps, curSum);
        return;
    }

    // try reg
    if (valid(x, y-1) && curSum + tiles[y-1][x] <= memo[y-1][x]) {
        memo[y-1][x] = curSum + tiles[y-1][x];
        solve(x, y-1, keyIdx, curSum + tiles[y-1][x]);
    }
    if (valid(x+1, y) && curSum + tiles[y][x+1] <= memo[y][x+1]) {
        memo[y][x+1] = curSum + tiles[y][x+1];
        solve(x+1, y, keyIdx, curSum + tiles[y][x+1]);
    }

    // try skips
    if (keyIdx >= key.size()) return;

    int jump = key[keyIdx++]-'0'+1;
    if (valid(x, y-jump) && curSum + tiles[y-jump][x] < memo[y-jump][x]) {
        memo[y-jump][x] = curSum + tiles[y-jump][x];
        solve(x, y-jump, keyIdx, curSum + tiles[y-jump][x]);
    }
    if (valid(x+jump, y) && curSum + tiles[y][x+jump] < memo[y][x+jump]) {
        memo[y][x+jump] = curSum + tiles[y][x+jump];
        solve(x+jump, y, keyIdx, curSum + tiles[y][x+jump]);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> xs >> ys;
    cin >> key;
    tiles = vector<vector<int>>(ys, vector<int>(xs));
    memo = vector<vector<int>>(ys, vector<int>(xs, oo));
    for (int i = 0; i < ys; i++) {
        string inp; cin >> inp;
        for (int j = 0; j < xs; j++)
            tiles[i][j] = inp[j]-'0';
    }
    
    minSteps = oo;
    solve(0, ys-1, 0, tiles[ys-1][0]);

    cout << minSteps << nl;

    return 0;
}
