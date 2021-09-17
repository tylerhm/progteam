#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string inp; cin >> inp;
    ll len = inp.length();
    
    // find the first non-question mark
    int loc = -1;
    for (int i = 0; i < len; i++)
        if (inp[i] != '?') {
            loc = i;
            break;
        }

    // special case all question marks
    // 20^((len + 1) / 2) * 6^(len / 2) + 20^(len / 2) * 6^((len + 1) / 2);
    if (loc == -1) {
        ll a = pow(20, (len + 1) / 2);
        ll b = pow(6, len / 2);
        ll c = pow(20, len / 2);
        ll d = pow(6, (len + 1) / 2);
        
        cout << a*b + c*d << endl;
        return 0;
    }

    bool startIsVowel = vowels.count(inp[loc]);
    int startPeriod = loc % 2;

    ll ans = 1;
    for (int i = 0; i < len; i++) {
        int locPeriod = i % 2;
        if (inp[i] == '?') {
            // has to be a vowel
            if (locPeriod == startPeriod)
                ans *= startIsVowel ? 6 : 20;
            else
                ans *= startIsVowel ? 20 : 6;
        } else {
            // check for validity
            if (locPeriod == startPeriod) {
                if (startIsVowel != vowels.count(inp[i])) {
                    cout << 0 << endl;
                    return 0;
                }
            } else if (startIsVowel == vowels.count(inp[i])) {
                cout << 0 << endl;
                return 0;
            }
        }
    }

    cout << ans << endl;

    return 0;    
}
