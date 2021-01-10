#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

bool validS(pair<int, int> back, pair<int, int> front) {
    return (front.first < back.first && front.second < back.second);
}
bool validD(pair<int, int> back, pair<int, int> front) {
    return (front.second < back.first && front.first < back.second);
}

void solve(int t) {
    int n; cin >> n;
    vector<pair<int, int>> friends(n);
    pair<int, int> sVF = make_pair(1e9, 1e9), sVS = make_pair(1e9, 1e9), sVT = make_pair(1e9, 1e9);
    int svfi = -1, svsi = -1, svti = -1;
    pair<int, int> sHF = make_pair(1e9, 1e9), sHS = make_pair(1e9, 1e9), sHT = make_pair(1e9, 1e9);
    int shfi = -1, shsi = -1, shti = -1;
    for (int i = 0; i < n; i++) {
        int h, w; cin >> h >> w;
        friends[i].first = h; friends[i].second = w;
        if (h > w) {
            if (h < sVF.first) {
                sVF = friends[i];
                svfi = i;
            }
            if (w < sVS.second) {
                sVS = friends[i];
                svsi = i;
            }
            if (w < sVT.first && h < sVT.second) {
                sVT = friends[i];
                svti = i;
            }
        }
        else {
            if (h < sHF.first) {
                sHF = friends[i];
                shfi = i;
            }
            if (w < sHS.second) {
                sHS = friends[i];
                shsi = i;
            }
            if (w < sHT.first && h < sHT.second) {
                sHT = friends[i];
                shti = i;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int h = friends[i].first;
        int w = friends[i].second;
        bool standing = h > w;

        if (standing) {
            if (validS(friends[i], sVF)) {
                cout << (svfi+1) << " ";
                continue;
            }
            if (validS(friends[i], sVS)) {
                cout << (svsi+1) << " ";
                continue;
            }
            if (validS(friends[i], sVT)) {
                cout << (svti+1) << " ";
                continue;
            }
            if (validD(friends[i], sHF)) {
                cout << (shfi+1) << " ";
                continue;
            }
            if (validD(friends[i], sHS)) {
                cout << (shsi+1) << " ";
                continue;
            }
            if (validD(friends[i], sHT)) {
                cout << (shti+1) << " ";
                continue;
            }
        }
        else {
            if (validD(friends[i], sVF)) {
                cout << (svfi+1) << " ";
                continue;
            }
            if (validD(friends[i], sVS)) {
                cout << (svsi+1) << " ";
                continue;
            }
            if (validD(friends[i], sVT)) {
                cout << (svti+1) << " ";
                continue;
            }
            if (validS(friends[i], sHF)) {
                cout << (shfi+1) << " ";
                continue;
            }
            if (validS(friends[i], sHS)) {
                cout << (shsi+1) << " ";
                continue;
            }
            if (validS(friends[i], sHT)) {
                cout << (shti+1) << " ";
                continue;
            }
        }
        cout << -1 << " ";
    }
    cout << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tt; cin >> tt;
    for (int t = 1; t <= tt; t++)
        solve(t);

    return 0;
}
