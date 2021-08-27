#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j,0,sz(jmp[k]))
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b);
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

vector<vi> adjList;
vector<pii> lcaVec;
map<int, int> rmqLocs;
void getLcaVec(int parent, int curNode, int depth) {
    rmqLocs[curNode] = lcaVec.size();
    lcaVec.emplace_back(depth, curNode);

    for (int child : adjList[curNode])
        if (child != parent) {
            getLcaVec(curNode, child, depth + 1);
            lcaVec.emplace_back(depth, curNode);
        }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    adjList = vector<vi>(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    getLcaVec(-1, 0, 0);

    RMQ rmq(lcaVec);

    ll dist = 0;
    for (int i = 1; i <= n / 2; i++) {
        int base = i;
        for (int mult = 2*base; mult <= n; mult += base) {
            int uLoc = rmqLocs[i-1];
            int vLoc = rmqLocs[mult-1];

            auto u = lcaVec[uLoc];
            auto v = lcaVec[vLoc];

            int ud = u.first;
            int vd = v.first;

            int lca = rmq.query(min(uLoc, vLoc), max(uLoc, vLoc)).first;

            dist += ud + vd - 2*lca + 1;
        }
    }

    cout << dist << endl;

    return 0;    
}
