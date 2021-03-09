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

    ll n, m; cin >> n >> m;

    map<int, int> lastUnread;
    ll totalMessages = 0;
    

    ll sender, unread;
    rep(i, 0, m) {
        totalMessages++;
        unread = 0;
        cin >> sender;
        lastUnread[sender] = totalMessages;
        for (auto p : lastUnread)
            unread += totalMessages - p.second;
        unread += (n - lastUnread.size()) * totalMessages;
        cout << unread << "\n";
    }

    return 0;    
}
