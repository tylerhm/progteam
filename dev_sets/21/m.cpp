#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int t) {

    // Number of buildings (number of students)
    int n; cin >> n;

    // Number of movement iterations
    int k; cin >> k;

    // Holds where each building points to
    vector<int> movesTo(n + 1);

    // Populate array
    for (int i = 1; i <= n; i++) {
        int buildingIPointsTo; cin >> buildingIPointsTo;
        movesTo[i] = buildingIPointsTo;
    }

    // Where students are located
    vector<int> studentLocations(n + 1);

    // Populate the student locations.
    for (int i = 1; i <= n; i++) {
        int student; cin >> student;
        studentLocations[student] = i;
    }

    // Simulate
    for (int i = 0; i < k; i++)
        for (int j = 1; j <= n; j++)
            studentLocations[j] = movesTo[studentLocations[j]];

    vector<int> buildingToStudent(n + 1);

    for (int i = 1; i <= n; i++)
        buildingToStudent[studentLocations[i]] = i;

    for (int i = 1; i <= n; i++) cout << buildingToStudent[i] << " ";
    cout << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int c; cin >> c;
    for (int t = 1; t <= c; t++) solve(t);

    return 0;    
}
