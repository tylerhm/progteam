#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string inp; cin >> inp;

    int firstU = -1, lastF = -1;
    for (int i = 0; i < inp.length(); i++) {
        if (inp[i] == 'U' && firstU == -1) firstU = i;
        if (inp[i] == 'F') lastF = i;
    }

    for (int i = 0; i < inp.length(); i++) {
        if (i < firstU) inp[i] = '-';
        if (i > firstU && i < lastF) inp[i] = 'C';
        if (i > lastF) inp[i] = '-';
    }

    cout << inp << endl;

    return 0;    
}
