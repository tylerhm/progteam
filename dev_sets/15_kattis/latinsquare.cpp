#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

int n;
vector<vector<int>> square;
vector<vector<bool>> usedCols, usedRows;
vector<int> toTest;

void printBoard() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << square[i][j] << ' ';
		}
		cout << nl;
	}
}

bool solve(int row, int col) {
	if (col == n && row == n-1) return true;
	if (col == n) return solve(row+1, 0);

	if (square[row][col] != 0) return solve(row, col+1);

	for (int i : toTest) {
		if (usedCols[col][i] || usedRows[row][i]) continue;
		square[row][col] = i;
		usedCols[col][i] = true;
		usedRows[row][i] = true;
		if (solve(row, col+1))
			return true;
		square[row][col] = 0;
		usedCols[col][i] = false;
		usedRows[row][i] = false;
	}
	return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int k; cin >> n >> k;
	square = vector<vector<int>>(n, vector<int>(n, 0));
	usedCols = vector<vector<bool>>(n+1, vector<bool>(n+1, false));
	usedRows = vector<vector<bool>>(n+1, vector<bool>(n+1, false));
	set<int> toRemove;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int val; cin >> val;
			toRemove.insert(val);
			if (val == 0) continue;
			if (usedCols[j][val] || usedRows[i][val]) {
				cout << "NO" << nl;
				return 0;
			}
			usedCols[j][val] = true;
			usedRows[i][val] = true;
			square[i][j] = val;
		}
	}

	toTest = vector<int>();
	for (int i = 1; i <= n; i++) {
		if (toRemove.count(i)) continue;
		toTest.push_back(i);
	}

	if (solve(0, 0)) {
		cout << "YES" << nl;
		printBoard();
	}
	else {
		cout << "NO" << nl;
	}
    return 0;
}
