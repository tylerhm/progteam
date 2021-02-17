#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	vector<bool> usedRows(8, false), usedCols(8, false);
	vector<bool> usedUpRight(15, false), usedUpLeft(15, false);

	vector<string> inp(8);
	for (auto &s : inp) cin >> s;

	int numQueens = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (inp[i][j] == '.') continue;
			numQueens++;
			int col = j;
			int row = i;
			int upRight = col - row + 7;
			int upLeft = col + row;
			if (usedRows[row] || usedCols[col] ||
				usedUpRight[upRight] || usedUpLeft[upLeft]) {
					cout << "invalid" << nl;
					return 0;
			}
			usedRows[row] = true;
			usedCols[col] = true;
			usedUpRight[upRight] = true;
			usedUpLeft[upLeft] = true;
		}
	}

	if (numQueens == 8)
		cout << "valid" << nl;
	else
		cout << "invalid" << nl;

    return 0;
}
