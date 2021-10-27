#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string reg;
string word;
int dp[101][101];

bool match(int locReg, int locWord) {
	if (locReg == sz(reg) && locWord == sz(word)) return true;
	if (locReg >= sz(reg) || locWord >= sz(word)) return false;

	auto &ans = dp[locReg][locWord];
	if (ans != -1) return ans;

	// if our regex is at a *, we can either
	// stay on * and jump
	// move off of * and not jump

	bool valid;
	if (reg[locReg] == '*') {
		valid = 
		match(locReg, locWord + 1) || 
		match(locReg + 1, locWord) || 
		match(locReg + 1, locWord + 1);
	}
	else {
		if (reg[locReg] != word[locWord]) return (ans = 0);
		valid = match(locReg + 1, locWord + 1);
	}

	if (valid) ans = 1;
	else ans = 0;
	return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> reg;
    int num; cin >> num;
    for (int i = 1; i <= num; i++) {
		for (int j = 0; j < 101; j++)
			for (int k = 0; k < 101; k++)
				dp[j][k] = -1;
        cin >> word;
		if (match(0, 0)) cout << word << endl;
    }

    return 0;
}

