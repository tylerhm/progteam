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

    int n, k; cin >> n >> k;

    map<string, int> subjectDepth;

    string subj; getline(cin, subj);
    int depth;
    rep(i, 0, k) {
        getline(cin, subj);
        depth = 1;
        while (subj.length() >= 4 && subj.substr(0, 4) == "Re: ") {
            subj.erase(0, 4);
            depth++;
        }
        subjectDepth[subj] = max(subjectDepth[subj], depth);
    }

    int minMail = 0;
    for (auto s : subjectDepth)
        minMail += s.second;

    cout << (n >= minMail ? "YES" : "NO") << endl;

    return 0;    
}
