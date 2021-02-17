#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

bool addOne(string s, int index) {
    
}

bool getExl(string s) {
    
}

void solve(int t) {
    string s;
    cin >> s;

    string test = "";
    for (int i = 0; i < s.size(); i++) {
        s += "-";
        if (getExl(s))
            return;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int tt; cin >> tt;
	for (int t = 0; t < tt; t++)
		solve(t);    

    return 0;
}
