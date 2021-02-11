#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; cin >> n;
    set<pair<pair<int, int>, int>> lookup;
    vector<pair<pair<int, int>, int>> defective;
    for (int i = 0; i < n; i++) {
        int x, y, z; cin >> x >> y >> z;
        lookup.insert({{x, y}, z});
        defective.push_back({{x, y}, z});
    }

    vector<int> dx = {1, -1, 0, 0, 0, 0}, dy = {0, 0, 1, -1, 0, 0}, dz = {0, 0, 0, 0, 1, -1};

    int wallCount = 0;
    for (int i = 0; i < n; i++) {
        auto point = defective[i];
        int x = point.first.first;
        int y = point.first.second;
        int z = point.second;
        for (int j = 0; j < 6; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            int nz = z + dz[j];
            if (!lookup.count({{nx, ny}, nz}))
                wallCount++;
        }
    }

    cout << wallCount << nl;

    return 0;
}
