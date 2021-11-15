#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int LEN = 2000;
const int MAX_OP = 51;

int n, a, b;
int at[MAX_OP], bt[MAX_OP];

int dp[MAX_OP][MAX_OP][LEN][2];
// [idxA][idxB][diffBetween][lastMove]
const int A = 0, B = 1;

int go(int idxA, int idxB, int diff, int lastMove) {
    if (idxA == a && idxB == b) return 0;

    auto &ans = dp[idxA][idxB][diff][lastMove];
    if (ans != -1) return ans;

    int aLoc, bLoc;
    if (lastMove == A) {
        aLoc = at[idxA - 1];
        bLoc = aLoc + diff;
    } else {
        bLoc = bt[idxB - 1];
        aLoc = bLoc - diff;
    }

    int bestDist = INT_MAX;

    // move A
    if (idxA < a) {
        int aMove = at[idxA];
        int distToA = abs(aMove - aLoc) + 1;

        int bAttemptMove = bt[idxB];

        int bMove;
        if (bAttemptMove < bLoc) bMove = max(aMove + 1, max(bLoc - distToA, bAttemptMove));
        else bMove = max(aMove + 1, min(bLoc + distToA, bAttemptMove));

        int bDiff = bMove - aMove;
        bestDist = min(bestDist, go(idxA + 1, idxB, bDiff, A) + distToA);
    }

    // move B
    if (idxB < b) {
        int bMove = bt[idxB];
        int distToB = abs(bMove - bLoc) + 1;

        int aAttemptMove = at[idxA];

        int aMove;
        if (aAttemptMove < aLoc) aMove = min(bMove - 1, max(aLoc - distToB, aAttemptMove));
        else aMove = min(bMove - 1, min(aLoc + distToB, aAttemptMove));

        int aDiff = bMove - aMove;
        bestDist = min(bestDist, go(idxA, idxB + 1, aDiff, B) + distToB);
    }

    // move and take both A and B
    if (idxA < a && idxB < b) {
        int aMove = at[idxA];
        int bMove = bt[idxB];
        int distToA = abs(aMove - aLoc) + 1;
        int distToB = abs(bMove - bLoc) + 1;
        int diff = bMove - aMove;
        if (aMove < bMove && distToA == distToB)
            bestDist = min(bestDist, go(idxA + 1, idxB + 1, diff, A) + distToA);
    }

    return ans = bestDist;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> n >> a >> b;
    rep(i,0,a) cin >> at[i], at[i]--;
    rep(i,0,b) cin >> bt[i], bt[i]--;

    for (int i = 0; i < MAX_OP; i++)
        for (int j = 0; j < MAX_OP; j++)
            for (int k = 0; k < LEN; k++)
                for (int l = 0; l < 2; l++)
                    dp[i][j][k][l] = -1;

    int dist = go(1, 1, n - 1, A) + 1;
    cout << dist << endl;

    return 0;
}

