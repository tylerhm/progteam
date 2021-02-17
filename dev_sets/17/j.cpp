#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

vector<vector<bool>> matrix;
ll n;
  

bool isCover(ll V, ll k, ll E) 
{ 
    ll set = (1 << k) - 1; 
    ll limit = (1 << V); 
    vector<vector<bool>> visited; 
  
    while (set < limit) 
    { 
        visited = vector<vector<bool>>(n+10, vector<bool>(n+10, false));
        int cnt = 0; 
        for (int j = 1, v = 1; j < limit; j = j << 1, v++) 
        { 
            if (set & j) 
            { 
                // Mark all edges emerging out of this 
                // vertex visited 
                for (int k = 1; k <= V; k++) 
                { 
                    if (matrix[v][k] && !visited[v][k]) 
                    { 
                        visited[v][k] = true; 
                        visited[k][v] = true; 
                        cnt++; 
                    } 
                } 
            } 
        } 
  
        if (cnt == E) 
            return true; 
  
        ll c = set & -set;
        ll r = set + c; 
        if (c == 0) 
            set = (((r^set) >> 2) / 1) | r;
        else
            set = (((r^set) >> 2) / c) | r;
    } 
    return false; 
} 
  
int findMinCover(int n, int m) 
{
    int left = 1, right = n; 
    while (right > left) 
    { 
        int mid = (left + right) >> 1; 
        if (!isCover(n, mid, m)) 
            left = mid + 1; 
        else
            right = mid; 
    } 
  
    return left; 
} 
  
void connect(int u, int v) 
{ 
    matrix[u+1][v+1] = true; 
    matrix[v+1][u+1] = true;
}

double pairDist(pair<ll, ll> a, pair<ll, ll> b) {
    ll dx = a.first-b.first, dy = a.second-b.second;
    return sqrt(dx*dx + dy*dy);
}

void solve() {

    if (n == 1) {
        cout << 1 << nl;
        return;
    }

    vector<pair<ll, ll>> points(n);
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        points[i].first = x;
        points[i].second = y;
    }

    // build graph
    matrix = vector<vector<bool>>(n+10, vector<bool>(n+10, false));
    int edges = 0;
    for (int i = 0; i < points.size(); i++) {
        for (int j = i+1; j < points.size(); j++) {
            if (i == j) continue;
            if (pairDist(points[i], points[j]) < 1.3) {
                connect(i, j);
                edges++;
            }
        }
    }

    cout << n - findMinCover(n, edges) << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    while (true) {
        try {
            cin >> n;
            solve();
        }
        catch (...) {
            return 0;
        }
    }
    return 0;
}
