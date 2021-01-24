#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;


// number =  000111000111000
// shifted = 001110001110000
// xor =     001001001001000
// out =     000111000111000

// algo, every time you find a one start or stop a run


// number =  011011010011010
// shifted = 110110100110100
// xor =     101 101 11 0101 110
// out =     011 011 01 0011 010

// 187 case
// number = 10111011
// shift =  01110110
// xor =    11001101
// out =    01000100

bool on(int mask, int pos) { return (mask & (1 << pos)) > 0; }
int setb(int mask, int pos) { return mask | (1 << pos); }

void print(int val) {
    for (int i = 7; i >= 0; i--)
        cout << (on(val, i)?1:0);
    cout << nl;
}

void solve(int t) {
    int b; cin >> b;
    //print(b);
    int numOn = 0;
    for (int i = 7; i >= 0; i--)
        if (on(b, i)) numOn++;

    int ans = 0;
    bool inRun = numOn&1?true:false;
    for (int i = 7; i >= 0; i--) {
        if (inRun)
            ans = setb(ans, i);
        if (on(b, i)) {
            if (!inRun)
                inRun = true;
            else
                inRun = false;
        }
    }
    //print(ans);
    cout << ans << ' ';
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
