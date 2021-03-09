#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<string, int> events;
map<int, string> indexToEvent;
int curIndex = 0;

string eval() {
    int num; cin >> num;
    int negate = 0;
    int stay = -1;

    rep(i, 0, num) {
        string s; cin >> s;
        if (s[0] == '!') {
            string cut = s.substr(1);
            if (events.count(cut))
                negate = max(negate, (int)events.size()-events[cut]);
        }
        else {
            if (!events.count(s))
                return "Plot Error";
            else
                stay = max(events[s], stay);
        }
    }

    if (negate == 0) return "Yes";
    if (stay >= events.size() - negate) return "Plot Error";
    return to_string(negate) + " Just A Dream";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    rep(i, 0, n) {
        string op; cin >> op;
        if (op[0] == 'E') {
            string event; cin >> event;
            indexToEvent[curIndex] = event;
            events[event] = curIndex++;
        } else if (op[0] == 'D') {
            int num; cin >> num;
            rep(j, 0, num) {
                events.erase(indexToEvent[--curIndex]);
                indexToEvent.erase(curIndex);
            }
        } else {
            int num; cin >> num;
            int negate = 0;
            int stay = -1;

            vector<string> scene(num);
            for (auto &s : scene) cin >> s;

            bool earlyBreak = false;
            for (auto s : scene) {
                if (s[0] == '!') {
                    string cut = s.substr(1);
                    if (events.count(cut))
                        negate = max(negate, (int)events.size()-events[cut]);
                }
                else {
                    if (!events.count(s)) {
                        cout << "Plot Error\n";
                        earlyBreak = true;
                        break;
                    }
                    else
                        stay = max(events[s], stay);
                }
            }

            if (earlyBreak) continue;
            if (negate == 0) cout << "Yes\n";
            else if (stay >= events.size() - negate) cout << "Plot Error\n";
            else cout << to_string(negate) + " Just A Dream\n";
        }
    }

    return 0;    
}
