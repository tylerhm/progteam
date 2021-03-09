#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    stack <pair<int,int>> hills;
    int hill;
    pair <int,int> next;
    long ans = 0;
    for (int i=0;i<n;i++){
        cin >> hill;
        next = make_pair(hill,1);
        while (!hills.empty()) {
            if (hills.top().first < hill) {
                ans += hills.top().second;
                hills.pop();
            }
            else if (hills.top().first == hill) {
                ans += hills.top().second;
                next.second += hills.top().second;
                hills.pop();
            }
            else
                break;
        }
        if (!hills.empty())
            ans++;
        hills.push(next);
    }
    cout << ans << "\n";
    return 0;
}